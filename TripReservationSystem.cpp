#include <iostream>
using namespace std;
/**************Class Trip******************
*******************************************
******************************************/
class Trip {
private:
string source;
string destination;
float distance;
string carType;
float fee;
int points;
public:
Trip();
Trip(string s, string d, float dist, string type);
void calculateFee();
void calculatePoints();
void printTrip();
int getPoints();
float getFee();
};

Trip::Trip(){
source = "***";
destination = "***";
distance = 0;
carType = "***";
fee = 0;
points = 0;
}
Trip::Trip(string s, string d, float dist, string type){
source = s;
destination = d;
distance = dist;
carType = type;
calculateFee();
calculatePoints();
}

void Trip::calculateFee(){
if (carType == "economy")
fee = 2 + distance * 5.2 / 3;
else if (carType == "family")
fee = 3 + distance * 7.5 /3;
else if (carType == "luxury")
fee = 5 + distance * 9.4 /3;
}
void Trip::calculatePoints(){
points = static_cast<int>(fee)/10; /*since int cannot store float values*/
}
void Trip::printTrip(){
cout << "*** Trip Information ***\n";
cout << "Source: " << source << endl;
cout << "Destination: " << destination << endl;

cout << "Distance: " << distance << " KM" << endl;
cout << "Car Type: " << carType << endl;
cout << "Fee: " << fee << " SR" << endl;
cout << "Points collected from this trip: " << points << endl;
cout << "***********************************************************\n";
}
int Trip::getPoints(){
return points;
}
float Trip::getFee(){
return fee;
}
/**************Class User******************
*******************************************
******************************************/

int m=1;
class User {
private:
string fullName;
string userName;
string password;
int currentTrips;
int totalPoints;
Trip tripList[5];

public:
User();
void storeInformation();
void generateUserName();
bool verifyPassword(string p);
void printInformation();
bool addTrip(Trip t);
void printTrips();
void updatePoints(float f);
string getUserName();
string getPassword();
int getTotalPoints();
};
User::User(){
fullName = "**";
userName = "**";
password = "**";
currentTrips = 0;
totalPoints = 0;
}
void User::storeInformation(){
cout << "*** USER LOGIN ***" << endl;
cout << "Enter full name: ";
getline(cin, fullName); //cin.ignore();
getline(cin, fullName);
string pass;
do{
cout << "Enter your password (it must be 8-character long and contains at least a digit and an uppercase letter): ";
cin >> pass;
if (verifyPassword(pass)){
password = pass;
cout << "Your password has been set correctly.\n";
}
else
cout << "Invalid password!\n";
}
while(verifyPassword(pass) == false);

generateUserName();
}
void User::generateUserName(){
int target;
string first, second;
target = fullName.find(' ') + 1;
first = fullName.substr(0,1);
second = fullName.substr(target,1);
userName = first + second + "_" + to_string(m);
++m;
}
bool User::verifyPassword(string p){
bool found1 = false, found2 = false;
if(p.length()>=8) /* should be greater or equal to eight */
{
for(int i=0; i<p.length(); i++){
if(p[i]>='A' && p[i]<='Z') /* at least one uppercase */
found1 = true;
else if (p[i] >= '0' && p[i] <= '9') /* at least one digit */
found2 = true;
}
}
if(found1 && found2)
return true;
return false;
}

void User::printInformation(){
string hiddenPass;
cout << "Name: " << fullName << endl;
cout << "Username: " << userName << endl;
hiddenPass = password;
for (int i=0; i<hiddenPass.length()-2; i++)
hiddenPass[i]='*';
cout << "Password: " << hiddenPass << endl;
cout << "-----------------------------------------------------------\n";
}
bool User::addTrip(Trip t){
if (currentTrips < 5){
tripList[currentTrips] = t;
totalPoints += tripList[currentTrips].getPoints();
++currentTrips;
return true;
}
return false;
}
void User::printTrips(){

if( currentTrips == 0)
cout << "No trips booked!\n";
else
for (int i=0; i<currentTrips; i++){
tripList[i].printTrip();
}
}
void User::updatePoints(float f){
if(f >= getTotalPoints() ){
cout << "Fee is now " << f - totalPoints << " SR\n";
totalPoints=0;
}
else{
cout << "Fee is now 0 SR\n";
totalPoints -= f; }
}
int User::getTotalPoints(){
return totalPoints;
}
string User::getUserName(){
return userName;
}
string User::getPassword(){
return password;
}

User reg[10];
int i=0;
int main ()
{
string s, dest, type;
float d;
int choice1, choice2, j, num;
do
{
cout << "1. Admin" << endl << "2. User" << endl << "3. Exit" << endl;
cout << "Enter your choice: ";
cin >> choice1;
if (choice1 == 1)
{
cout << "1. Register user" << endl;
cout << "2. Print users information" << endl;
cout << "3. Exit" << endl;
cout << "Enter your choice: ";
cin >> choice2;
while (choice2 != 3)
{
switch (choice2)
{
case 1:
{
reg[i].storeInformation();
i++;
break;
}
case 2:
{
for(j=0; j<i; j++)
reg[j].printInformation();
break;
}
case 3:
{
break;
}
}/*end switch*/
cout << "1. Register User" << endl;
cout << "2. Print Users Information" << endl;

cout << "3. Exit" << endl;
cout << "Enter your choice: ";
cin >> choice2;
}/*end while*/
}/*end if*/

else if (choice1 == 2)
{
bool found =false;
string uName, pass;
cout << "***LOGIN***\nUsername: ";
cin >> uName;
cout << "Password: ";
cin >> pass;
for(j=0; j<i; j++)
if (uName == reg[j].getUserName() && pass == reg[j].getPassword() ){
found=true;
break;}
while( !found )
{
cout << "Invalid username or password! please try again.\n";
cout << "Username: ";
cin >> uName;
cout << "Password: ";
cin >> pass;
for(j=0; j<i; j++)
if (uName == reg[j].getUserName() && pass == reg[j].getPassword() ){
found=true;
break;}
}
cout << "Login successfully!\n";
cout << "1. Book a trip" << endl;
cout << "2. Print points" << endl;
cout << "3. Print trip History" << endl;
cout << "4. Exit" << endl;
cout << "Enter your choice: ";
cin >> choice2;
while (choice2 != 4)
{
switch (choice2)
{
case 1:
{
cout << "Enter source: ";
cin >> s;
cout << "Enter destination: ";
cin >> dest;
cout << "Enter distance: ";
cin >> d;
cout << "Enter car type: ";
cin >> type;
Trip tr(s,dest,d,type);
if (reg[j].addTrip(tr)){
cout << "Trip is booked successfully!\n";
tr.printTrip();

if ( reg[j].getTotalPoints() > 0){

cout << "Do you want to use your points for this trip?\n1. Yes\n2. No\n";
cin >> num;
if(num==1){
reg[j].updatePoints(tr.getFee());}
}
}

else

cout << "Cannot book more trips!\n";
break;
}
case 2:
{
cout << "Points collected: " << reg[j].getTotalPoints() << endl;
break;
}
case 3:
{
reg[j].printTrips();
break;
}
case 4:
{
break;
}
}/*end switch*/
cout << "1. Book a trip" << endl;
cout << "2. Print points" << endl;
cout << "3. Print trip History" << endl;
cout << "4. Exit" << endl;
cout << "Enter your choice: ";
cin >> choice2;
}/*end while*/
}/*end else if*/
}
while (choice1 != 3); /*end do-while*/
}/*end main*/