# Day 1 - Core Concepts
Syntax Semantics / ABI / Idioms - Patterns

* **Build Process**
    * Data Memory <=> Micro Proc <=> registers <=> opcode
    * **Compilation**
        1. Preprocessor (replaces #includes with actual code) 
        2. Whitespace removal
        3. Tokenizing [ (a+++b) -> (a++ + b) maximal munch ]
        4. Syntax analysis => errors 
        5. Intermediate Representation
        6. Semantic Analysis => Warnings 
        7. Optimization
        8. Code Generation
            * Data Definitions
            * Program Opcodes
            * Symbol Table
            * Debug Info
            * Exports
            * Imports
        9. Linking => Symbol Resolution => One Definition Rule

* **The C++ object model**  
Data:
 [     Compile Time/Static (allocated in compile time)(Program  opcodes/ Data Definitions(.data/.bss-set to zero/.const)/ andreas@andreas:~/CLionProjects/AdvancedRTCPP$ 
)      | 
     Runtime (during execution)(Stack(local)/Heap(dynamic)/Registers)      ]  
	* **Definition**
		* For function: Allocates the address
		* For objects (anything that occupies memory):   
			Type Gives:  
				* Amount of memory
				* How to interpret memory (int/float)
					* Size-Qualification (short/long)
					* Sign-Qualification (signed/unsigned)
				* The operations allowed

			Initialization =/= Assignment  
			Brace initialization ```int i {10};```  
			Null ptr initialization ```int* ptr {nullptr}```;  
	* **Declaration**  
		Look for address in imports table  
		Global Scope operator 
		```c++
        int x {1000};
        int main(){
            int x {256};
            std::cout << x << std::endl;
            std::cout << ::x << std::endl;
        }
		```  
		Lifetime:  
		* Outside of block: Program Lifetime, located in static memory
		* In block: Block Lifetime, Runtime 
		* static global -> filename scope (internal linkage)
	* **Expressions**
		* Values, Types, Category (lvalue, rvalue)
			* rvalues: yield temporary objects, can't take the address of
			* lvalues: previously defined objects, objects with names

* **User-Defined Types**
	* **Structures**  
		```c++
		struct Example{
			int i;
			char c;
		};
		```
		Structure members are public 
		Structures represent collections of information (they are datatypes)  
		They support aggregate initializers
		```c++
		Example ex1;
		Example ex2{};
		Example ex3{200, 'x'};
		```
		Brace elision  
		```c++
		struct Inner{
			int arr[2];
		}
		sturct Outer{
			Inner inner;
			int other_data;
		}

		int main(){
			Inner inner1;
			Inner inner2 {};
			Inner inner3 { {1,2}};
			Inner inner4 {1,2}; // brace ellision, same as above

			Outer outer1;
			Outer outer2 {};
			Outer outer3 {{1, 2}, 3}; // Explicit
			Outer outer4{inner{1 ,2}, 3}; // Copy-initialization of inner
			Outer outer5{1,2,3}; // brace ellision of inner and outer
		}
		``` 
  
	* **Classes**
		Classes represent behaviours  
		```c++
		class Position{
		public:
			Position() = default; // = delete would disable
			Position(double azi, double elev):rho{elev}, theta{elev}{};

			void show();
			void set_elevation(double inc);
			void set_azimuth(double azi);
		private:
			double rho {0.0};
			double theta {0.0}; // default initializers
		}
		```  

# Day 2

### Functions
* [Compiler Explorer](www.godbolt.org)
* **Intel stack-based calling conversion**  

	* Call Frame
	* Stack Frame

* **ARM regsiter-based calling convention**  
	* Who cares


* **Function Parameters**
	* **Input**: provided objects
		* Pass-by-value:  
			Need to copy => call to copy constructor and destructor  
			Functions that happen in destructor will be triggered when copy goes out of scope
		* Constructor as conversion functions
		```c++
		class Interlock{
		public:
			explicit Interlock(bool lockstate): locked{lockstate}{}
			explicit Interlock(int lockstate): locked{lockstate > 0}{} //use explicit to disable type conversions
			bool is_locked() {return locked;}
			void set(bool locked_state) {locked = lock_State;}
		private:
			bool locked{false};
		}

		Interlock lock = false; // cakk to bool constructor
		
		int i {20};
		lock = i; //temp Interlock, and call to int constructor
		```	 
		* Implicit conversion might not be desired, use explicit keyword*
		
		```c++
		class USART{
		public:
			...
			// disable copy constructor so class can never be passed by value
			USART(const USART&) = delete;
			...
		}
		```
		
		* Constant objects as Input parameters:
			* TIL: References
			* Mark member functions as const
		* 			
	* **Output**: generated objects
		* Return-Value-Optimization => pass address of output args 
	* **Input/Output**: manipulated objects  
		* Non const-qualified references

	* **Flags**  
		* ```[[ noreturn ]]```
		* ```[[ nodiscard ]]```
		* ```[[ deprecated("Warning msg") ]]```
		* ```[[ maybe_unused ]]``` for parameters (interfaces etc.)	
	
	* **Automatic Type Deduction**  
		```c++
		auto e {1, 2, 3}; // error
		auto e = {1, 2, 3}; // works through type ellision
		auto ar[10]; // error, does not work for arrays
		```  

		* ```auto``` invalid for member variables and function parameters
		* Don't use for scalars
		* Don't use when initialization is not a function call

		Type deduction rules:  

		```c++
		const int const_val {100};
		const int& const_ref {const_val};
		int array[100];

		auto i { const_val }; // i => int, cv-qualifier discarded
		auto j { const_ref }; // j => int, reference ignored
		auto k { array };		// k => int*, array degeneration
		
		const auto l { const_val }	// l => const int
		const auto m { array } 		// m => int* const, constant pointer
		
		auto& n { const_val } // n => const int&
		auto& o { const_ref } // o => const int&
		auto& p { array } 	// p => const int

		cout << typeid(i).name() << endl;
		cout << typeid(j).name() << endl;
		cout << typeid(k).name() << endl;
		```
		
		```decltype(x) b``` gives the type of x, x is not evaluated, does not decay  

		```c++
		decltype(const_val) d {100}; // d => const int
		decltype(const_ref) e { d }; // e => const int&
		```
		---------------  
		```c++
		auto obj_1 = generate();
		auto obj_2 = obj_1; // obj_1 == obj_2
		```  
		vs
		```c++
		auto obj_1 { generate() };
		decltype(obj_1) obj_2 {}; // obj_1 =/= obj_2
		```  
	* **Constants**
		* Int/Float Literals
		* String Literals:
			* Raw String: R"(γξγκξηγκξγ)" => not interpeted  
			Can be delimited by something: R"--+--(dsagfdsafg)--+--"

		* Enums:
			Underlying type:
			```c++
			enum class Modde: unsigned long{
				of, on, standby, error
			};
			
			enum Direction: unsigned char{
				input, output
			};
			Mode current { Mode::standby };
			Direction dir {output};
			```

		* const
			Once initialized, does not change  
			```c++
			int size {10};			// size not const
			const int sz { size }; 	// non-modifiable, run-time initialized
			double array[size];		// error
			double array2[sz];		// erro, C++ does not support VLAs
			```

		* constexpr  
			Compile time constants
			```c++
			int size {16};
			const int const_sz {16};
			
			constexpr int array_1{100};		//ok
			constexpr int array_2{size};	//fail
			constexpr int array_3{const_sz};//fail

			double array[100];
			double arrayp[const_sz];
			```
		```const``` is for function parameters, ```constexpr``` for constants
* **Connecting Objetcs**
	* Need to see header and address of object to communicate with

# Day - 3  

### **Specializations**  

	* Subtyping and Derived Typing, same in C++
	* Specialization through inheritance

	```c++
	class Sensor{
	public:
		Sensor() = default;
		Sensor(int id, bool is_active);
		double get_value();
	protected: // provide protected methods for interfacing, and getting/setting
		void set_active();
		std::string as_string();
	private:
		int ID 	     {0};
		double value {};
		bool active  {false};
	}
	
	class RotaryEncoder: public Sensor{ // gives access to Sensor public attributes
	public:
		using Sensor::Sensor; // makes all base class consructors visible within encoder scopei

		RotaryEncoder(int id, bool state, double fac, double g):
			Sensor {id, state};
			conv_factor {fac};
			gain{g};
		{
			std::cout << "New Rotary Encoder" << <std::endl;
			std::cout << Sensor::as_string() << std::endl;
		}
	private:
		double conv_factor { 1.0 };
		double gain		   { 1.0 };
	}

	RotaryEncoder enc1 {}; // OK
	RotaryEncoder enc2 {2, false}; //Error without the using directive
	```
### SOLID
* **S**
* **O**pen-closed:
* **L**iskov-Substitution: Must provide same functionality to client, and not demand more
* **I**
* **D**
  
###	Inheritance

* Using substitutable derived classes  
 	[Client]->[Sensor]  ====> [Client]->[RotaryEncoder]
	* Only a pointer needs to change, can be done at runtime

	* Use inheritance if change needs to be a runtime, and if substitution is necessary
		* If substitution is not necessary, use **composition**
		* If change is not needed at runtime, use **templates** for generatlity and performance  
	
	* Derivation Rules / Object Slicing:
		* Base objects can point to derived objects and base objects (can slice objects)
		* Derived objects cannot point to base objects (cannot extend objects)
	
	```c++
	class Sensor{
	public:
		double get_value(){
			std::cout<<"Base::get_value"<<std::endl;
			return data;
		}
	};

	class RotaryEncoder: public Sensor{
		double get_value(){
			std::cout << "RotaryEncoder::get_value" << std::endl;
			return data;
		}
	};
	
	void read_sensor(Sensor &ptr){
		ptr.get_value(); // Dynamic binding bia reference
	}
	
	sensor.get_value(); // Sensor::ge_value
	encoder.get_value(); // RotaryEncoder::get_value;
	read_sensor(&sensor); // Sensor::get_value();
	read_sensor(&encoder) // Sensor::get_value();
	```

	change function to ```virtual```
	
	```c++
    class Sensor{
    public:
        virtual double get_value(){ // is expected to be overriden
            std::cout<<"Base::get_value"<<std::endl;
            return data;
        }
    };

    class RotaryEncoder: public Sensor{
        double get_value() override { // overrides base function 
            std::cout << "RotaryEncoder::get_value" << std::endl;
            return data;
        }
    };
	```
	* Base class should be explicitly constructed
	* Add a virtual destructor if there are virtual functions
	* Mark overriden functions in derived classes
