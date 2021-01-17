#include <iostream>
#include <fstream>
#include <conio.h>
//#include "vld.h"
using namespace std;

class Helper
{
public:
	static int stringLen(char arr[])
	{
		if (arr)
		{
			int i;
			for (i = 0; arr[i]; i++);
			return i;
		}
	}
	static char* getStringFromBuffer(char* arr)
	{
		int size = stringLen(arr);
		char *temp = new char[size + 1];
		int i;
		for (i = 0; i < size; i++)
			temp[i] = arr[i];
		temp[i] = '\0';
		return temp;
	}
	static void stringConcat(char arr[], char brr[])
	{
		int i;
		for (i = 0; arr[i] != ':'; i++);
		i++;

		for (int j = 0; brr[j]; i++, j++)
			arr[i] = brr[j];

		return;
	}
	static void stringConcat2(char arr[], char brr[])
	{
		int i, j;
		for (i = 0; arr[i]; i++);
		for (j = 0; brr[j]; j++, i++)
			arr[i] = brr[j];
		arr[i] = '\0';
	}
	static bool stringCmp(char arr[], char brr[])
	{
		int size = stringLen(arr);
		int size2 = stringLen(brr);
		if (size == size2)
		{
			for (int i = 0; i < size; i++)
			{
				if (arr[i] != brr[i])
					return false;
			}
			return true;
		}
		return false;
	}
	static void stringCopy(char arr[], char brr[])
	{
		int i;
		for (i = 0; brr[i]; i++)
			arr[i] = brr[i];
		arr[i] = '\0';
	}
};

struct classList
{
	int count;
	char names[60][15];
	char rollNo[60][10];

	classList()
	{
		count = 0;
	}
	void insertInSec(char* n, char* r)
	{
		if (count < 60)
		{
			Helper::stringCopy(names[count], n);
			Helper::stringCopy(rollNo[count], r);
			count++;
		}
	}
	void printStudents()
	{
		for (int i = 0; i < count; i++)
			cout << "Name: " << names[i] << "\t" << "Roll No.: " << rollNo[i] << endl;
	}

};


struct nodeC
{
	char* courseName;
	char* csRoom;
	classList* record;
	nodeC* next;

	//Functions
	nodeC()
	{
		courseName = 0;
		csRoom = 0;
		record = 0;
		next = 0;
	}
};

class Courses
{
private:
	nodeC* first;
public:
	Courses()
	{
		first = 0;
	}
	void insert(char c[], char r[])//, classList* &recrd)
	{
		nodeC* temp = new nodeC;
		temp->courseName = Helper::getStringFromBuffer(c);
		temp->csRoom = Helper::getStringFromBuffer(r);
		//temp->record = recrd;
		//recrd = 0;
		if (!first)
			first = temp;
		else
		{
			nodeC* curr = first;
			while (curr->next != 0)
				curr = curr->next;
			curr->next = temp;
		}
	}
	void printCourse()
	{
		nodeC* curr = first;
		while (curr)
		{
			cout << "Course Name: " << curr->courseName << "(" << curr->csRoom << ")" << " , ";
			curr = curr->next;
		}
	}
	nodeC* getFirst()
	{
		return first;
	}
	~Courses()
	{
		nodeC* prev = first;
		while (first)
		{
			first = first->next;
			if (prev->courseName != 0)
			{
				delete[] prev->courseName;
				prev->courseName = 0;
			}
			if (prev->csRoom != 0)
			{
				delete[] prev->csRoom;
				prev->csRoom = 0;
			}
			if (prev->record != 0)
			{
				delete prev->record;
				prev->record = 0;
			}
			prev->next = 0;
			delete prev;
			prev = first;
		}
		prev = first = 0;
	}

};


class Time
{
private:
	char *sTime, *eTime;
	Courses* head;
public:
	Time()
	{
		sTime = eTime = 0;
		head = 0;
	}
	void setsTime(char* &arr)
	{
		if (arr)
			sTime = Helper::getStringFromBuffer(arr);
	}
	void seteTime(char* &arr)
	{
		if (arr)
			eTime = Helper::getStringFromBuffer(arr);
	}
	void setHead(Courses* arr)
	{
		head = arr;
	}
	Courses* getHead()
	{
		return head;
	}
	void printTime()
	{
		cout << "\nTime:\n";
		cout << sTime << "-" << eTime << " ::: ";
		head->printCourse();
		cout << endl;
	}
	Courses* getCourseObj()
	{
		return head;
	}
	char* getSTime()
	{
		return sTime;
	}
	char* getETime()
	{
		return eTime;
	}
	/*~Time()
	{
	if (sTime)
	delete[] sTime;
	if (eTime)
	delete[] eTime;
	}*/
	~Time()
	{
		if (sTime)
		{
			delete[] sTime;
			sTime = 0;
		}
		if (eTime)
		{
			delete[] eTime;
			eTime = 0;
		}
		if (head)
		{
			delete head;
			head = 0;
		}
	}
};

class Days
{
private:
	char* name;
	Time* timming;
public:
	Days()
	{
		name = 0;
		timming = 0;
	}
	void setName(char* &arr)
	{
		if (arr)
			name = Helper::getStringFromBuffer(arr);

	}
	void setTimming(Time* t)
	{
		timming = t;
	}
	void print()
	{
		cout << name << endl;
		for (int i = 0; i<8; i++)
			timming[i].printTime();
		cout << endl << endl << endl;
	}
	Time* getTimming()
	{
		return timming;
	}
	char* getDayName()
	{
		return name;
	}
	//~Days()
	//{
	//	if (name)
	//		delete[] name;
	//}
	~Days()
	{
		if (name)
		{
			delete[] name;
			name = 0;
		}
		if (timming)
		{
			delete[] timming;
			timming = 0;
		}
	}
};

//------------------------------------------- Classes for part B

struct secNode
{
	char* secName;
	classList* studentsEnrolled;
	secNode* next;
	secNode()
	{
		secName = 0;
		studentsEnrolled = 0;
		next = 0;
	}
};

class Section
{
	secNode* headOfSec;
	secNode* lastOfSec;
public:
	Section()
	{
		headOfSec = 0;
		lastOfSec = 0;
	}
	void insertASection(char* &sName, char* &studentName, char* &rollNo)
	{
		secNode *tempS = new secNode;

		tempS->secName = Helper::getStringFromBuffer(sName);
		//temp->studentsEnrolled->insertInSec(studentName, rollNo);

		if (!headOfSec)
		{
			tempS->studentsEnrolled = new classList;
			tempS->studentsEnrolled->insertInSec(studentName, rollNo);
			headOfSec = tempS;
			lastOfSec = tempS;
		}
		else
		{
			bool found = false;
			secNode* curr = headOfSec;
			while (curr != 0 && found == false)
			{
				if (Helper::stringCmp(curr->secName, tempS->secName)) //If sec already exists
				{
					curr->studentsEnrolled->insertInSec(studentName, rollNo);	//then simply enroll student in it
					found = true;
				}

				curr = curr->next;
			}

			if (found == false)
			{
				tempS->studentsEnrolled = new classList;
				tempS->studentsEnrolled->insertInSec(studentName, rollNo);
				lastOfSec->next = tempS;
				lastOfSec = tempS;
			}
		}
	}
	void printSection()
	{
		secNode* currS = headOfSec;
		while (currS != 0)
		{
			cout << "Section Name: " << currS->secName << endl;
			currS->studentsEnrolled->printStudents();
			currS = currS->next;
		}
	}
	secNode* getHeadOfSec()
	{
		return headOfSec;
	}
	~Section()
	{
		secNode* prev = headOfSec;
		while (headOfSec)
		{
			headOfSec = headOfSec->next;
			if (prev->secName)
			{
				delete[] prev->secName;
				prev->secName = 0;
			}
			if (prev->next)
				prev->next = 0;
			delete prev;
			prev = headOfSec;
		}
		headOfSec = prev = lastOfSec = 0;
	}
};

struct CINode
{
	char* courseName;
	Section* sec;
	CINode* next;
	char* getCourseName()
	{
		return courseName;
	}
	CINode()
	{
		courseName = 0;
		sec = 0;
		next = 0;
	}
	~CINode()
	{
		if (courseName)
		{
			delete[] courseName;
			courseName = 0;
		}
		if (sec)
		{
			delete sec;
			sec = 0;
		}

	}
};
class CourseInfo
{
private:
	CINode* headOfC;
	CINode* lastOfC;
public:
	CourseInfo()
	{
		headOfC = lastOfC = 0;
	}
	void insertACourse(char* rNo, char* studentName, char* cName, char* sName)
	{
		CINode* tempC = new CINode();
		tempC->courseName = Helper::getStringFromBuffer(cName);
		//temp->sec->insertASection(sName, studentName, rNo);
		if (!headOfC)
		{
			tempC->sec = new Section;
			tempC->sec->insertASection(sName, studentName, rNo);
			headOfC = tempC;
			lastOfC = tempC;
		}
		else
		{
			CINode* curr = headOfC;
			bool found = false;
			while (curr != 0 && found == false)
			{
				if (Helper::stringCmp(curr->courseName, tempC->courseName))//if already declared course
				{
					curr->sec->insertASection(sName, studentName, rNo);
					found = true;
				}

				curr = curr->next;
			}

			if (found == false)	//if new course
			{
				tempC->sec = new Section;
				tempC->sec->insertASection(sName, studentName, rNo);
				lastOfC->next = tempC;
				lastOfC = tempC;
			}
		}
	}
	void printCourses()
	{
		CINode* curr = headOfC;
		while (curr != 0)
		{
			cout << "Course Name: " << curr->courseName << endl;
			curr->sec->printSection();
			curr = curr->next;
		}
	}
	CINode* getCourseHead()
	{
		return headOfC;
	}
	~CourseInfo()
	{
		CINode* prev = headOfC;
		while (headOfC)
		{
			headOfC = headOfC->next;
			delete prev;
			prev = headOfC;
		}
		headOfC = prev = lastOfC = 0;
	}
};


class TTADT
{
private:
	Days* day;
	CourseInfo* course;
	char** venueForMonWed;
public:
	TTADT()
	{
		day = new Days[5];
		course = new CourseInfo;
		venueForMonWed = 0;
	}
	void setVenueForMonWed(char** &v)
	{
		venueForMonWed = v;
	}
	char** getVenueForMonWed()
	{
		return venueForMonWed;
	}
	void load(char fileName[])
	{
		int tSize = 9, vSize = 28, wSize = 5;		//TimeH size, VenueV size, Working Days Size
		char buffer[1000];
		char** time = new char*[tSize];
		char** venue = new char*[vSize - 2];			//Venue for mon and wed
		char** venue2 = new char*[vSize - 4];		//Venue for tues
		char** venue3 = new char*[vSize - 3];		//Venue for Thursday
		char** venue4 = new char*[vSize - 2];		//Venue for friday
		char** workingDays = new char*[wSize];
		char**** record = new char***[wSize];

		for (int i = 0; i < wSize; i++)
		{
			record[i] = new char**[vSize];
			for (int j = 0; j < vSize; j++)
				record[i][j] = new char*[tSize - 1];		//becoz 7 courses in a day are taught
		}
		for (int i = 0; i < vSize-2; i++)
			venue[i] = 0;
		for (int i = 0; i < vSize - 4; i++)
			venue2[i] = 0;
		for (int i = 0; i < vSize - 3; i++)
			venue3[i] = 0;
		for (int i = 0; i < vSize - 2; i++)
			venue4[i] = 0;
		for (int i = 0; i < wSize; i++)
			workingDays[i] = 0;

		for (int i = 0; i < wSize; i++)
		{
			for (int j = 0; j < vSize; j++)
			{

				for (int k = 0; k < (tSize - 1); k++)
				{
					record[i][j][k] = 0;
				}
			}
		}

		char fileExt[] = ".csv";
		Helper::stringConcat2(fileName, fileExt);
		ifstream fin;
		fin.open(fileName);
		if (fin.is_open())
		{
			char brr[] = "30";
			for (int i = 0; i < 3; i++)
			{
				fin.getline(buffer, 1000, '\n');		//Skip first three lines
			}
			fin.getline(buffer, 1000, ',');	//Days
			fin.getline(buffer, 1000, ',');	//Room
			for (int z = 0, i = 0; z < 5; z++)
			{
				fin.getline(buffer, 1000, ',');			//8.00am
				time[i] = Helper::getStringFromBuffer(buffer);
				i++;
				for (int j = 0; j < 5; j++)			//skip next five cells
					fin.getline(buffer, 1000, ',');
				if (z != 4)		//not read 7.30 after 8.00pm
				{
					fin.getline(buffer, 1000, ',');		//9.00am
					time[i] = Helper::getStringFromBuffer(buffer);
					Helper::stringConcat(time[i], brr);			//9.30am
					i++;

					for (int j = 0; j < 11; j++)			//skip till 11.00am
						fin.getline(buffer, 1000, ',');
				}
			}

			//Loads time of tSize succesfully
			fin.getline(buffer, 1000, '\n');		//Move to the next Line
			int tempVSize = 0;
			for (int s = 0; s<wSize; s++)
			{
				if (s == 0 || s == 2 || s == 4)
					tempVSize = vSize - 2;
				else if (s == 1)
					tempVSize = vSize - 4;
				else
					tempVSize = vSize - 3;
				for (int lecNoV = 0; lecNoV < tempVSize; lecNoV++)
				{
					if (lecNoV == 0)
					{

						fin.getline(buffer, 1000, ',');			//Reads working day on line cs1
						workingDays[s] = Helper::getStringFromBuffer(buffer);

					}
					else {
						fin.getline(buffer, 1000, ',');			//Skips the first cell from line cs2 and onwards

					}

					fin.getline(buffer, 1000, ',');		//CS-1

					if (s == 0)
						venue[lecNoV] = Helper::getStringFromBuffer(buffer);
					else if (s == 1)
						venue2[lecNoV] = Helper::getStringFromBuffer(buffer);
					else if (s == 3)
						venue3[lecNoV] = Helper::getStringFromBuffer(buffer);
					else
						venue4[lecNoV] = Helper::getStringFromBuffer(buffer);


					for (int classNoH = 0; classNoH < (tSize - 1); classNoH++)
					{
						fin.getline(buffer, 1000, ',');	//Machine Lear...
							record[s][lecNoV][classNoH] = Helper::getStringFromBuffer(buffer);

						for (int i = 0; i < 8; i++)//skip 8 cells
							fin.getline(buffer, 1000, ',');

					}

					fin.getline(buffer, 1000, '\n');//Move to next line

				}
				//if (s == 0 || s == 2 || s==4)	// (Mon,Wed & fri)->Lectures=25 and (tue&thur)->Lectures=24
				fin.getline(buffer, 1000, '\n');

			}

			fin.close();


		}


		else
			cout << "File Not Opened!!\n";

		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		//Loading in Data Structure

		//First of All make LL of courses then append it to Time class and the append that Time class to Days[i]

		//Making LL of Courses


		//for (int i = 0; i<5; i++)
		//	cout << workingDays[i];

		////_getch();
		//for (int i = 0; i < vsize - 2; i++)
		//	cout << venue[i] << endl;
		//_getch();
		//cout << endl << endl;
		/*
		for (int i = 0; i < vSize - 4; i++)
		cout << venue2[i] << endl;
		_getch();

		cout << endl << endl;

		for (int i = 0; i < vSize - 3; i++)
		cout << venue3[i] << endl;
		_getch();

		cout << endl << endl;

		for (int i = 0; i < vSize - 2; i++)
		cout << venue4[i] << endl;
		_getch();

		for (int i = 0; i < 5; i++)
		cout << workingDays[i] << endl;
		_getch();
		*/
		cout << endl << endl;

		for (int d = 0; d<5; d++)
		{
			day[d].setName(workingDays[d]);
			Time* tArr = new Time[tSize - 1];
			for (int i = 0; i<(tSize - 1); i++)
			{
				tArr[i].setsTime(time[i]);
				tArr[i].seteTime(time[i + 1]);


				Courses* cObj = new Courses;

				if (d == 0 || d == 2)
				{
					for (int lecNoV = 0; lecNoV < (vSize - 2); lecNoV++)		//As for mon and wed we only have 26 venues
						cObj->insert(record[d][lecNoV][i], venue[lecNoV]);
				}
				else if (d == 1)
				{
					for (int lecNoV = 0; lecNoV < (vSize - 4); lecNoV++)		//As for tues
						cObj->insert(record[d][lecNoV][i], venue2[lecNoV]);
				}
				else if (d == 3)
				{
					for (int lecNoV = 0; lecNoV < (vSize - 3); lecNoV++)	//On Thurs there are 25 venues
						cObj->insert(record[d][lecNoV][i], venue3[lecNoV]);
				}
				else
				{
					for (int lecNoV = 0; lecNoV < (vSize - 2); lecNoV++)	//On Fri there are 26 venues
						cObj->insert(record[d][lecNoV][i], venue4[lecNoV]);
				}

				tArr[i].setHead(cObj);
			}
			day[d].setTimming(tArr);

		}
		//setVenueForMonWed(venue);
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/*for (int d = 0; d<5; d++)
		{
		day[d].print();
		}*/

		for (int i = 0; i < tSize; i++)
			delete time[i];
		delete[] time;

		for (int i = 0; i < (vSize - 2); i++)
			delete venue[i];
		delete[] venue;

		for (int i = 0; i < (vSize - 4); i++)
			delete venue2[i];
		delete[] venue2;

		for (int i = 0; i < (vSize - 3); i++)
			delete venue3[i];
		delete[] venue3;

		for (int i = 0; i < (vSize - 2); i++)
			delete venue4[i];
		delete[] venue4;


		for (int i = 0; i < wSize; i++)
			delete workingDays[i];
		delete[] workingDays;
		for (int i = 0; i < wSize; i++)
		{
			if (!record[i])
				break;
			for (int j = 0; j < vSize; j++)
			{
				if (!record[i][j])
					break;
				for (int k = 0; k < (tSize - 1); k++)
				{

				//	if (!record[i][j][k])
					//	break;
				//	delete[] record[i][j][k];
				}
				delete[] record[i][j];
			}
			delete[] record[i];
		}
		delete[] record;



	}
	void loadStudentInfo(char fileName[])
	{
		char rollBuffer[100], namebuffer[100], courseBuffer[100], secBuffer[100], buffer[1000];
		int fileSize = 8003;
		char fileExt[] = ".csv";
		Helper::stringConcat2(fileName, fileExt);
		ifstream fin;
		fin.open(fileName);

		if (fin.is_open())
		{
			fin.getline(buffer, 1000, '\n');		//Skips the first line of roll name course and section
			for (int i = 0; i < fileSize; i++)
			{
				fin.getline(rollBuffer, 100, ',');

				fin.getline(namebuffer, 100, ',');

				fin.getline(courseBuffer, 100, ',');

				fin.getline(secBuffer, 100);

				course->insertACourse(rollBuffer, namebuffer, courseBuffer, secBuffer);

				//	else
				//		course->insertACourse(rollBuffer, namebuffer, courseBuffer, secBuffer);
				//	fin.getline(buffer, 1000, '\n');
			}
		}
		else
			cout << "File Not Found!!" << endl;

		//-----------------------Printing the linked Courses, Sections and students

		//course->printCourses();



	}
	void linkingStudentsToCourses()
	{
		Days* currDay = day;
		Time* currTime = 0;
		nodeC* headOfCourse = 0;
		char space[] = " (";
		char cBrac[] = ")";
		for (int i = 0; i < 5; i++)		//For every day
		{
			currTime = currDay[i].getTimming();
			for (int i = 0; i < 8; i++)		//Every time of a day
			{
				headOfCourse = currTime[i].getCourseObj()->getFirst();		//Head of each course in timming[i] from *day
				while (headOfCourse != 0)
				{
					CINode* curr = course->getCourseHead();		//Points to the head of courses from *Courses
					while (curr != 0)
					{
						secNode* tempSecHead = curr->sec->getHeadOfSec();
						while (tempSecHead != 0)
						{
							char tempCourse[100];
							Helper::stringCopy(tempCourse, curr->courseName);
							Helper::stringConcat2(tempCourse, space);		// concat (

							Helper::stringConcat2(tempCourse, tempSecHead->secName);
							Helper::stringConcat2(tempCourse, cBrac);
							if (Helper::stringCmp(headOfCourse->courseName, tempCourse))
							{
								//			cout << headOfCourse->courseName << "   " << tempCourse << endl;
								//_getch();
								headOfCourse->record = tempSecHead->studentsEnrolled;
								break;
							}

							tempSecHead = tempSecHead->next;
						}
						curr = curr->next;
					}


					headOfCourse = headOfCourse->next;
				}

			}
		}
		currDay = 0;
		currTime = 0;
	}

	void saveClashes()
	{
		ofstream fout;
		fout.open("clash.txt");
		Days* currDay = day;				//Time from days class
		int no = 1;
		for (int i = 0; i < 5; i++)
		{
			Time* currTime = currDay[i].getTimming();		//Time of from days class
			for (int j = 0; j < 8; j++)
			{
				nodeC* currCourse = currTime[j].getCourseObj()->getFirst();		//Courses from days class
				while (currCourse)
				{
					classList* myStudents = currCourse->record;		//Students of this course
					if (myStudents)		//If students exist
					{
						int size = myStudents->count;
						for (int k = 0; k < size; k++)					//For every students
						{
							nodeC* nextCourse = currCourse->next;		//The next parallel course
							while (nextCourse)
							{
								classList* myNextStudent = nextCourse->record;		//Check every student for repitition
								if (myNextStudent)
								{
									int size2 = myNextStudent->count;
									for (int z = 0; z < size2; z++)				//Checking every students enrolled in the next course
									{
										if (Helper::stringCmp(myStudents->rollNo[k], myNextStudent->rollNo[z]))
										{
											cout << no << ") " << currDay[i].getDayName() << "    " << currTime[j].getSTime() << "-" << currTime[j].getETime() << endl;
											cout << myStudents->names[k] << " " << myStudents->rollNo[k] << endl;
											cout << currCourse->courseName << "  " << nextCourse->courseName << endl;
											cout << endl << endl;
											no++;
											break;
										}
									}
								}
								nextCourse = nextCourse->next;
							}	//For every course after the curr course
						}
					}//For 60 students in a course
					currCourse = currCourse->next;
				}

			}
		}
		fout.close();
		currDay = 0;
	}
	void printStudentsTimeTable(char rollNo[])
	{
		Days* currDay = day;				//Time from days class
		bool visited[5];
		for (int i = 0; i < 5; i++)
			visited[i] = 0;

		for (int i = 0; i < 4; i++)
		{
			if (visited[i] == false)
			{
				Time* currTime = currDay[i].getTimming();		//Time of from days class
				for (int j = 0; j < 8; j++)
				{
					nodeC* currCourse = currTime[j].getCourseObj()->getFirst();		//Courses from days class
					while (currCourse)
					{
						classList* myStudents = currCourse->record;		//Students of this course
						if (myStudents)		//If students exist
						{
							int size = myStudents->count;
							for (int k = 0; k < size; k++)					//For every students
							{
								if (Helper::stringCmp(rollNo, myStudents->rollNo[k]))			//If Student is found
								{
									cout << currCourse->courseName << ":" << endl;
									cout << currDay[i].getDayName() << " " << currTime[j].getSTime() << ":" << currTime[j].getETime() << "," << currCourse->csRoom;
									char* courseName = Helper::getStringFromBuffer(currCourse->courseName);		//For the next comming days check for this course
									for (int z = i + 1; z < 5; z++)
									{
										Time* tempTime = currDay[z].getTimming();
										for (int h = 0; h < 8; h++)
										{
											nodeC* tempCourse = tempTime[h].getCourseObj()->getFirst();
											while (tempCourse)
											{
												if (Helper::stringCmp(courseName, tempCourse->courseName))  //if the same course is found print
												{
													visited[z] = true;
													cout << " || " << currDay[z].getDayName() << " " << tempTime[h].getSTime() << ":" << tempTime[h].getETime() << "," << tempCourse->csRoom;
												}
												tempCourse = tempCourse->next;
											}
										}
									}
									cout << endl << endl;
								}
							}
						}//For 60 students in a course
						currCourse = currCourse->next;
					}

				}
			}
		}
	}
	void printCourse(char d[], char t[], char r[])
	{
		Days* currDay = day;				//Time from days class
		bool found = false;
		for (int i = 0; i < 5 && found == false; i++)
		{
			if (Helper::stringCmp(d, currDay[i].getDayName()))
			{
				Time* currTime = currDay[i].getTimming();		//Time of from days class
				for (int j = 0; j < 8 && found == false; j++)
				{
					if (Helper::stringCmp(t, currTime[j].getSTime()))
					{
						nodeC* currCourse = currTime[j].getCourseObj()->getFirst();		//Courses from days class
						while (currCourse && found == false)
						{
							if (Helper::stringCmp(r, currCourse->csRoom))
							{
								cout << currCourse->courseName;
								found = false;
								//				break;
							}
							currCourse = currCourse->next;
						}
					}
				}
			}
		}
		currDay = 0;
	}
	void printCourseTimming(char cName[], char sName[])
	{
		Days* currDay = day;
		char space[] = " (";
		char cBrac[] = ")";
		for (int i = 0; i < 5; i++)		//For every day
		{
			Time* currTime = currDay[i].getTimming();
			for (int j = 0; j < 8; j++)		//Every time of a day
			{
				nodeC* headOfCourse = currTime[j].getCourseObj()->getFirst();		//Head of each course in timming[i] from *day
				while (headOfCourse != 0)
				{
					char tempCourse[100];
					Helper::stringCopy(tempCourse, cName);
					Helper::stringConcat2(tempCourse, space);		// concat (

					Helper::stringConcat2(tempCourse, sName);
					Helper::stringConcat2(tempCourse, cBrac);
					if (Helper::stringCmp(headOfCourse->courseName, tempCourse))
					{
						cout << currDay[i].getDayName() << " : ";
						cout << currTime[j].getSTime() << ":" << currTime[j].getETime() << endl;
					}
					headOfCourse = headOfCourse->next;
				}

			}
		}
		currDay = 0;
	}
	~TTADT()
	{
		cout << "Calling TTADT's Destructor\n";

		if (day)
		{
			delete[] day;
			day = 0;
		}
		if (course)
		{
			delete course;
			course = 0;
		}

	}
};

void main()
{
	TTADT obj1;
	char name[20] = "input";
	char name1[20] = "students";
	cout << "Enter timeTable file name:\n";
	//cin >> name;
	obj1.load(name);
	cout << "Enter students record's file name:\n";
	//cin >> name;
	obj1.loadStudentInfo(name1);
	cout << "Now Doing all the linking:\n\n";
	obj1.linkingStudentsToCourses();
	//char** venue = obj1.getVenueForMonWed();
	//for (int i = 0; i<26; i++)
	//cout << venue[i]<<endl;
	/*cout << "The Complete Data of Course and students:\n";
	obj1.printEveryThing();*/
	cout << "The Students with Clashes:\n";
	obj1.saveClashes();
	//_getch();
	//obj1.printStudentsTimeTable("457");

	obj1.printCourse("Monday", "9:30 a.m.", "CS-3");
	cout << endl << endl;
	obj1.printCourseTimming("Numerical Methods", "CS-B");
	cout << "\n\n\nGood Job";
	_getch();
}
