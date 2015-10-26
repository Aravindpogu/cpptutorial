// My first program
// Simple calculator app
#include   <iostream>

int main(){

	// Need a place to hold inputs
	int first=0, second=0, result =0;
	char operation ;
	bool done = false;

	// repeat until the user is done
	while(!done){
		//prompt user for equation
		std::cout << "Enter an equation : ";
		
		//get input fromm user
		std::cin >> first >> operation >> second ;
		
		//evaluate equation
		switch(operation){
			case '+' : result = first + second; break;
			case '-' : result = first - second; break;
			case '*' : result = first * second; break;
			case '/' : result = first / second; break;
			default : std::cout << "unknown op" << std::endl; break;
		}

		
		std::cout << "Result is : " << result << std::endl;
		std::cout << "Done (Y/n)? : ";

		char answer ;
		std::cin >>answer;

		if(answer == 'Y'){
			done = true;
		}
		
	}

}
