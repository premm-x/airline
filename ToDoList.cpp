#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class List 
{ public:
    int id;
    string task;
};

int ID=-1;
int choice;

void banner();
void load_id();
void add();
void show();
void search ();
void delet();
void option();
void update();
void edit();
void close();


int main(){
   load_id();
   system("cls");
   do {
     banner();
    cout<<endl<<endl<<"1. Add Task"<<endl;
    cout<<"----------------------"<<endl;
    cout<<"2. Show All Task"<<endl;
    cout<<"----------------------"<<endl;
    cout<<"3. Search Task"<<endl;
    cout<<"----------------------"<<endl;
    cout<<"4. Delete Task"<<endl;
    cout<<"----------------------"<<endl;
    cout<<"5. Update/Edit task"<<endl;
    cout<<"----------------------"<<endl;
    cout<<"6. Close programm"<<endl<<endl;

    cout<<endl<<"Enter your choise : ";
    cin>> choice;

    switch(choice){
        case 1: add();
        break;
        case 2: show();
        break;
        case 3: search();
        break;
        case 4: delet();
        break;
        case 5:option();
        break;
        case 6:close();
        break;
        default: cout<<"invalid syntax";
        break;
    }
   } while (ID!=321);
   return 0;
}

void banner(){
    cout<<"-----------------------------------"<<endl;
    cout<<"\t     To-Do List       "<<endl;
    cout<<"-----------------------------------"<<endl;
}

void load_id()
 {
   ifstream fin("todo.txt");
   List todo;
   
   while(fin >> todo.id)
   {
   	fin.ignore();
   	getline(fin, todo.task);
   	if(todo.id> ID){
   		ID = todo.id;
   	    }
	 }	
	 fin.close();
	 ID++;
 }

void add(){
	load_id();
    system("cls");
    banner();
    List todo;
    cout<<"Enter the new task : ";
    cin.get();
    getline(cin, todo.task);

    char save;
    cout<<"Save? (y/n)"<<endl;
    cin>>save;
    if(save == 'y'){
        //ID++;
        ofstream fout;
        fout.open("todo.txt" , ios::app); //to append the data in file
        fout<<"\n"<<ID;
        fout<<"\n"<<todo.task;
        fout.close();

        char more;
        cout<<"Add More Task? (y/n) : ";
        cin>>more;

        if(more == 'y'){
            add();
        }
        else{
            system("cls");
            cout<<"Task Added Successfully..!"<<endl;
            return;
        }
    }system("cls");

}

void show(){
    system("cls");
    banner();
    List todo;

    ifstream fin;
    fin.open("todo.txt");
    cout<<"Task : "<<endl;

    while(!fin.eof()){
        fin >> todo.id;
        fin.ignore();
        getline(fin, todo.task);
        if(todo.task != "" ){
            cout<<"\t"<<todo.id<<": "<<todo.task <<endl;
        }
        else{
            cout<<"Empty..!!"<<endl;
        }

    }
    fin.close();

    char exit;
    cout<<"\n\n Exit? (y/n)"<<endl;
    cin>>exit;
    if(exit != 'y'){
        show();
    }
    system("cls");
}

void delet(){
    system("cls");
    banner();
    int id;
    cout<<"Enter the task number : ";
    cin>>id;
    List todo;
    ifstream fin;
    fin.open("todo.txt");
        char del;
        cout<<"delete? (y/n)"<<endl;
        cin>>del;

        if(del == 'y'){
            ofstream tempfile;
            tempfile.open("temp.txt");

            int index = 1;

            while(!fin.eof()){
                fin >> todo.id;
                fin.ignore();
                getline(fin, todo.task);

                if(todo.id != id){
                    tempfile <<"\n"<< index;
                    tempfile <<"\n"<< todo.task;
                    index++;
                    ID--;
                }
            }
            fin.close();
            tempfile.close();
            remove("todo.txt");
            rename("temp.txt", "todo.txt");
            system("cls");
            cout<<"Delete Successfully..!"<<endl;
        }
        else{
            system("cls");
            cout<<"Not Deleted"<<endl;
        }
    }


void search()
 {
 	system("cls");
 	List todo;
 	banner();
 	int id ;
 	cout<< " Enter the id : ";
 	cin>> id;
 		ifstream fin ("todo.txt");
 		while(!fin.eof())
 		{
 			fin >> todo.id;
 			fin.ignore();
 			getline (fin,todo.task);
 			if(todo.id == id)
			 {
 			  system("cls");
 			  cout<<"\t"<<todo.id<<": "<<todo.task <<endl;
 			  return;
			}
 		}
		 system("cls");
		 cout<<" Not found !!"<<endl;
		 return;
		 }
		 
void option()
 {
	 system("cls");
	 banner();
	 char EU;
	 cout<<" Enter 'e' for Edit and 'u' for Update : "<<endl;
	 cin>> EU;
	 if(EU == 'e')
	 {
	 	system("cls");
	 	 edit();
	 }
	 else if (EU == 'u')
	 {
	 	system("cls");
	 	update ();
	 }
	 else {
	 	cout<<" Invaild Input!!... "<<endl;
	 }
 }
 
void edit()
 {
 	banner();
 	List todo;
 	ifstream fin;
    fin.open("todo.txt");
    int id1;
    string New_task;
    cout<<"Enter the id of task : "<< endl;
    cin>> id1;
    cout<<"Enter the Edit task : "<< endl;
     cin.get();
    getline(cin, New_task);
     char edi;
        cout<<"Edit? (y/n)"<<endl;
        cin>>edi;

        if(edi == 'y'){
            ofstream tempfile;
            tempfile.open("temp.txt");
            
            while(!fin.eof()){
                fin >> todo.id;
                fin.ignore();
                getline(fin, todo.task);

                if(todo.id != id1){
                    tempfile <<"\n"<< todo.id;
                    tempfile <<"\n"<< todo.task;
                }
                else
                {
                	tempfile <<"\n"<< id1;
                    tempfile <<"\n"<< New_task;
				}
            }
            fin.close();
            tempfile.close();
            remove("todo.txt");
            rename("temp.txt", "todo.txt");
            system("cls");
            cout<<"Edited Successfully..!"<<endl;
        }
                else{
            system("cls");
            cout<<"Not Edited"<<endl;
        }
    } 
 
void update()
 {
 	banner();
 	int id2;
 	string task1;
 	 cout<<"Enter the id of task : "<< endl;
    cin>> id2;
    cout<<"Enter the Update note : "<< endl;
     cin.get();
    getline(cin, task1);
     char Upa;
        cout<<"Update? (y/n)"<<endl;
        cin>>Upa;
        List todo;
      ifstream fin;
         fin.open("todo.txt");
         
        if(Upa == 'y'){
            ofstream tempfile;
            tempfile.open("temp.txt");
            
            while(!fin.eof()){
                fin >> todo.id;
                fin.ignore();
                getline(fin, todo.task);

                if(todo.id != id2){
                    tempfile <<"\n"<< todo.id;
                    tempfile <<"\n"<< todo.task;
                }
                else
                {
                	tempfile <<"\n"<< id2;
                    tempfile <<"\n"<< todo.task <<" "<<"("<<task1<<")";
				}
            }
            fin.close();
            tempfile.close();
            remove("todo.txt");
            rename("temp.txt", "todo.txt");
            system("cls");
            cout<<"Updated Successfully..!"<<endl;
        }
                else{
            system("cls");
            cout<<"Updation Cancelled...!!"<<endl;
        }
    } 
 
void close(){
    system("cls");
    char off;
    banner();
    cout<<" Are you sure you want to close the program (y/n) :- "<<endl;
    cin>>off;
    if(off=='y')
    {
      system("cls");
      ID=321;
      cout<<"Visit again..!"<<endl;
      cout<<"*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*";
    }
    
    else{
    	system("cls");
	}

}
