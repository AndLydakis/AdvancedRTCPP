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
		
	
