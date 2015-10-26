// My first program
// Simple calculator app
#include   <iostream>

int evaluate(int first, int second, char operation);
bool isDone();

int main(){

	// Need a place to hold inputs
	int first=0, second=0, result =0;
	char operation ;

	// repeat until the user is done
	do{
		//prompt user for equation
		std::cout << "Enter an equation : ";
		
		//get input fromm user
		std::cin >> first >> operation >> second ;
		
		//evaluate equation
		result = evaluate(first, second, operation);		

		std::cout << "Result is : " << result << std::endl;
	}while(!isDone());

	std::cout << "GoodBye" << std::endl;
}

int evaluate(int first, int second, char operation){
	int result =0;	
	switch(operation){
		case '+' : result = first + second; break;
		case '-' : result = first - second; break;
		case '*' : result = first * second; break;
		case '/' : result = first / second; break;
		default : std::cout << "unknown op" << std::endl; break;
	}
	return result;
}

bool isDone(){
	bool done=false;
	std::cout << "Done (Y/n)? : ";
	char answer ;

	std::cin >>answer;
	if(answer == 'Y' || answer == 'y'){
		done = true;
	}
	return done;
}
