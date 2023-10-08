#include <iostream>
#include <conio.h> 
#include <string> 
#include <stdlib.h> 
#include <ctime>

#define WRONGTRIES 5

using namespace std;

void DrawMan(int tries){
	cout<<endl<<endl;
	cout<<"  -----"<<endl;
	cout<<"  |   |"<<endl; 
	cout<<"  |"; if(tries>=1) cout<<"   O    "; cout<<endl;
	cout<<"  |"; if(tries>=3) cout<<"  /|\\   "; cout<<endl;
	cout<<"  |"; if(tries>=5) cout<<"  / \\    "; cout<<endl;
	cout<<"  |"<<endl; 
	cout<<"__|__"<<endl;
}

int main(){
	srand (time(NULL));
	string wordList[5] = {"elma","armut","muz","portakal","mango"};
	string word;
	string guessed;
	
	word = wordList[rand()%5];
	
	int wordLength = word.length();
	string dispWord (wordLength, '_');
	
	int found = 0;
	char guess = ' ';
	int tries = 5; 
	int flagFound = 0; 
	
	while(tries>=0){
		system("cls");
		cout<<"Meyveyi tahmin ediniz : "<<endl<<endl;
		 
		for(int i=0; i<wordLength; i++)
			cout<<" "<<dispWord[i]<<" "; 
		cout<<endl<<endl<<endl;
		 		
		cout<<"Yanlýþ Deneneler: "<<tries<<" / "<<WRONGTRIES<<endl;
		cout<<"Tahmin edilen harfler: "<<guessed<<endl; 
		
		DrawMan(tries);
		
		if( found == wordLength ){
			cout<<endl;
			cout<<"*****************"<<endl;
			cout<<"*    Kazandýnýz ! *"<<endl;
			cout<<"*****************"<<endl;
			break;
		}
		
		if( tries == 0) break; 
		
		cout<<"Harf seçiniz :";
		guess = getche();
		guessed = guessed + " " + guess;
		if( dispWord.find(guess)!=string::npos ) tries++;
		
		flagFound = 0;
		for(int i=0; i<wordLength; i++){
			if( word[i]==guess && dispWord[i]=='_' ){
				dispWord[i] = guess;
				found++;
				flagFound = 1; 
			}
		}
		 
		if( !flagFound )
			tries--;
	}
	if( found != wordLength ){
		cout<<endl;
		cout<<"******************"<<endl;
		cout<<"*    Kaybettiniz ! *"<<endl;
		cout<<"******************"<<endl;
	}
	getch();
	return 0;
}
