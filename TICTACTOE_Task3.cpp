#include<iostream>

using namespace std;

void display(char table[3][3]){
	for(int i=0; i<3 ; i++){
		for(int j=0; j<3 ; j++){
			cout<<table[i][j]<<" | ";
		}
		cout<<endl;
	}
}

bool win(char table[3][3], char user){

	for(int i=0; i<3 ; i++){
		if( (table[i][0]==user&&table[i][1]==user&&table[i][2]==user) ||
		    (table[0][i]==user&&table[1][i]==user&&table[2][i]==user)  ){
		        return true;
		
		}
			}
		
        if( (table[0][0]==user&&table[1][1]==user&&table[2][2]==user) ||
		    (table[0][2]==user&&table[1][1]==user&&table[2][0]==user)  ){
		        return true;
		}	//otherwise
		        return false;
		   }
		   
	bool draw(char table[3][3])	{
		for(int i=0; i<3 ; i++){
		for(int j=0; j<3 ; j++){
		   if(table[i][j]==' '){ //in this case 
		   		return false;
		   }
		}
	}
		    	return true;
}
		
	int main()	
	{
		char table[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
		char user1 = 'X';
		int col,row;
		
		while(true){
			cout<<"player "<<user1<<"'s turn"<<endl<<"Enter col(1-3), row(1-3)"<<endl;
			cin>>col>>row;
		
			col--;
			row--;
				if(table[col][row] !=' '){
				
				cout<<"Cell already taken, enter value again"<<endl;
				continue;
		}
		table [col][row] = user1;
			display(table);
				if(win(table,user1))	{
					cout<<"player"<<user1<<"is winner!"<<endl;
					break;
				}		
				if(draw(table)){
					cout<<"Game is DRAW! "<<endl;
					break;
				}
				
				if(user1 == 'X'){
				        user1 = 'O';
	            }
					else{
						user1 = 'X';
					}
		}
	return 0;	
}
		