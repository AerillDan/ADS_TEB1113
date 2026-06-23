#include <iostream>
#include <string>

using namespace std;

struct Student 
{
    string id;
    string name;
    string course;
    int age;
};

int main() {
    // Array for 5 students
    Student students[5];
    int total = 5;

    // Input data
    cout << "=== INPUT DATA ===\n";
    for (int i = 0; i < total; i++) 
		{
        cout << "Student " << i + 1 << " :\n";
        cout << "ID: ";
        cin >> students[i].id;
        cout << "Name: ";
        cin >> students[i].name;
        cout << "Course: ";
        cin >> students[i].course;
        cout << "Age: ";
        cin >> students[i].age;
        cout << "\n";
    	}

    // Display data
    cout << "=== STUDENT DATA ===\n";
    for (int i = 0; i < total; i++) 
		{
        cout << i + 1 << ". Student Record:\n";
        cout << "   ID:     " << students[i].id << "\n";
        cout << "   Name:   " << students[i].name << "\n";
        cout << "   Course: " << students[i].course << "\n";
        cout << "   Age:    " << students[i].age << "\n";
        cout << "-----------------------\n";
    	}

    // Linear Search
    string searchID;
    cout << "\n=== SEARCH ===\n";
    cout << "Enter ID to search: ";
    cin >> searchID;

    bool found = false;
    for (int i = 0; i < total; i++) 
		{
        if (students[i].id == searchID) 
				{
         	  cout << "Match Found!\n"; 
				  cout << "Name: " << students[i].name << "\n";
				  found = true;
				  break; 
        		}
    	}
		if (found == false)
			cout << "Match Not Found\n"

    // Update
    string updateID;
    cout << "\n=== UPDATE ===\n";
    cout << "Enter ID to update: ";
    cin >> updateID;

    bool updateFound = false;
    for (int i = 0; i < total; i++) 
		{
        if (students[i].id == updateID) 
		   {
            updateFound = true;
            
            cout << "What do you want to change? (name/course/age): ";
            string field;
            cin >> field;

            if (field == "name") 
				{
                cout << "Enter new name: ";
                cin >> students[i].name;
            } 
            else if (field == "course") 
				{
                cout << "Enter new course: ";
                cin >> students[i].course;
            } 
            else if (field == "age") 
				{
                cout << "Enter new age: ";
                cin >> students[i].age;
            }

            cout << "Record updated successfully!\n";
            break;
         }
    	}

    if (updateFound == false) 
        cout << "ID not found.\n";

    return 0;
}