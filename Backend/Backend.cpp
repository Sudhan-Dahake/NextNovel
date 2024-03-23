
#include <iostream>
#include <stdio.h>
#include <sqlite3.h>

using namespace std;

static int createDB(const char* s);
static int createUserTable(const char* s);
static int insertUserData(const char* s, string username, string firstName, string lastName, string email, string password);
static int callback(void* NotUsed, int argc, char** argv, char** azColName);
static int selectUserData(const char* s);

//static int deleteData(const char* s);

int main()
{
	// these cin statements are to try the database and insert data entered by the user into the USER table
	string first_name;
	string last_name;
	string email;
	string username;
	string password;

	cout << "Please enter your first name: " << endl;
	cin >> first_name;

	cout << "Please enter your last name: " << endl;
	cin >> last_name;

	cout << "Please enter your email: " << endl;
	cin >> email;

	cout << "Please enter your username: " << endl;
	cin >> username;

	cout << "Please enter your password: " << endl;
	cin >> password;


	const char* dir = "D:\\NextNovel\\Backend\\x64\\Debug\\NextNovelDB.db";  // directory where the database will be stored
	createDB(dir);  // create the database if it doesn't exist already
	createUserTable(dir);   // created the user table
	insertUserData(dir, first_name, last_name, email, username, password);  // insert the information entered by the user into the USER table
	selectUserData(dir);  // select all the data from the USER table to make sure they have been inserted correctly

	return 0;
}

// this function created a database in the directory specified
static int createDB(const char* s)
{
	sqlite3* DB;

	int exit = 0;
	exit = sqlite3_open(s, &DB);   // takes the directory string and opens that database and if a database is not there, it creates one

	sqlite3_close(DB);   

	return 0;
}

// this function created the USER table where it stores the information about the user
static int createUserTable(const char* s)
{
	sqlite3* DB;
	char* messageError;

	// Creating a database called USER
	string sql = "CREATE TABLE IF NOT EXISTS USER("    // 'IF NOT EXISTS' will avoid creating the table if it already exists. 
		"FIRST_NAME      VARCHAR NOT NULL, "
		"LAST_NAME     VARCHAR NOT NULL, "
		"EMAIL       VARCHAR  NOT NULL, "
		"USERNAME PRIMARY KEY, "    //the username of the user is set as the primary key, therefore two users cannot have the same username
		"PASSWORD   VARCHAR NOT NULL);";   


	// error handling
	try
	{
		int exit = 0;
		exit = sqlite3_open(s, &DB);
		/* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here */
		exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
		
		if (exit != SQLITE_OK) {
			cerr << "Error in createTable function." << endl;
			sqlite3_free(messageError);
		}
		else
			cout << "Table created Successfully" << endl;
		sqlite3_close(DB);
	}
	catch (const exception& e)
	{
		cerr << e.what();
	}

	return 0;
}

static int insertUserData(const char* s, string firstName, string lastName, string email, string username, string password)
{
	sqlite3* DB;
	char* messageError;

	string sql = "INSERT INTO USER (FIRST_NAME, LAST_NAME, EMAIL, USERNAME, PASSWORD) VALUES('" + string(firstName) + "', '" + string(lastName) + "', '" + string(email) + "', '" + string(username) + "', '" + string(password) + "');";

	int exit = sqlite3_open(s, &DB);
	/* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here */
	exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
	if (exit != SQLITE_OK) {
		// Check if the error is due to a constraint violation (duplicate username as the username is the primary key and two users cannot have the same username)
		if (sqlite3_errcode(DB) == SQLITE_CONSTRAINT_PRIMARYKEY) {
			cerr << "Error: Cannot enter, duplication in primary key (username)" << endl;
			return 2; // Return 2 to indicate duplicate username
		}
		else {
			cerr << "Error in insertData function: " << sqlite3_errmsg(DB) << endl;
			sqlite3_free(messageError);
			return exit; // Return the error code for other types of errors
		}
	}
	else
		cout << "Records inserted Successfully!" << endl;

}


static int selectUserData(const char* s)
{
	sqlite3* DB;
	char* messageError;

	string sql = "SELECT * FROM USER;";

	int exit = sqlite3_open(s, &DB);
	/* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here*/
	exit = sqlite3_exec(DB, sql.c_str(), callback, NULL, &messageError);

	if (exit != SQLITE_OK) {
		cerr << "Error in selectData function." << endl;
		sqlite3_free(messageError);
	}
	else
		cout << "Records selected Successfully!" << endl;

	return 0;
}

// retrieve contents of database used by selectData()
/* argc: holds the number of results, argv: holds each value in array, azColName: holds each column returned in array, */
static int callback(void* NotUsed, int argc, char** argv, char** azColName)
{
	for (int i = 0; i < argc; i++) {
		// column name and value
		cout << azColName[i] << ": " << argv[i] << endl;
	}

	cout << endl;

	return 0;
}



//static int deleteData(const char* s)
//{
//	sqlite3* DB;
//	char* messageError;
//
//	string sql = "DELETE FROM USER;";
//
//	int exit = sqlite3_open(s, &DB);
//	/* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here */
//	exit = sqlite3_exec(DB, sql.c_str(), callback, NULL, &messageError);
//	if (exit != SQLITE_OK) {
//		cerr << "Error in deleteData function." << endl;
//		sqlite3_free(messageError);
//	}
//	else
//		cout << "Records deleted Successfully!" << endl;
//
//	return 0;
//}
