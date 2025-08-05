#include <iostream>
#include <random>
#include <string>
#include<vector>
using namespace std;

int active=0;
int inactive=0;
int countt=0; //total count of telemenatry data vehicles to calculate average bettery
int battery=0; //sum of all battery percenatges
long long fleetDistance; //to calculate distance travelled by the fleet


vector<int> alert_battery;
vector<int> alert_speed;

void alert(int speed, int batteryPercentage){

    if(batteryPercentage<=15){
            alert_battery.push_back(1); //alert
        }else{
            alert_battery.push_back(0);
        }

        if(speed>50){
            alert_speed.push_back(1); //alert
        }else{
            alert_speed.push_back(0); 
        }

        int count_battery=0;
        for(int i=0; i<alert_battery.size();i++){
            if(alert_battery[i]==1){
                count_battery++;
                if(count_battery>=3) break;
            }else{
                count_battery=0;
            }
        }
        //printing after 3 consecutive alerts
        if(count_battery>=3){
            cout<<"Alert: Low on battery"<<endl;
            alert_battery.clear();
        }

        int count_speed=0;
        for(int j=0; j<alert_speed.size();j++){
            if(alert_speed[j]==1){
                count_speed++;
                if(count_speed>=3) break;
            }else{
                count_speed=0;
            }
        }
        //printing after 3 consecutive alerts
        if(count_speed>=3){
            cout<<"Alert: OVERSPEEDING"<<endl;
            alert_speed.clear();
        }
}


class Vehicle{
    public:
    long long VIN; //Vehicle Identification Number
    string Manufacturer;
    string Model;
    string fleetType; //"Corporate", "Rental", "Personal"
    long long fleetId;
    string status; //Registration status: Active, Maintenance, Decommissioned
    string owner;


//Real-time Telemetry Data Processing
//Later Integrate APIs
    int latitude;
    int longitude;
    int batteryPercentage;
    string engineStatus; // On, Off, Idle
    int speed;
    int odometerReading;
    int timeStamp;
    

    void create(long long VIN_, string Manufacturer_, string Model_, string fleetType_, long long fleetId_, string status_, string owner_){
        VIN=VIN_;
        Manufacturer=Manufacturer_;
        Model=Model_;
        fleetType=fleetType_;
        fleetId=fleetId_;
        status=status_;
        owner=owner_;
    }

    void create(){

        cout<<"Vehicle Identification Number: ";
        cin>>VIN;
  
        cout<<"Manufacturer: ";
        cin>>Manufacturer;
      
        cout<<"Model: ";
        cin>>Model;
      
        cout<<"fleet type(Corporate, Rental, Personal): ";
        cin>>fleetType;

        cout<<"Fleet ID: ";
        cin>>fleetId;
  
        cout<<"Status(Active, Inactive): ";
        cin>>status;

        cout<<"Owner: ";
        cin>>owner;

        if (status == "Active") active++;
        else if (status == "Inactive") inactive++;

    }

//to generate dummy values of telementary data
    void telementaryData(){

    random_device rd;
    mt19937 gen(rd());

    // Random generators
    uniform_real_distribution<> latDist(-90.0, 90.0);
    uniform_real_distribution<> lonDist(-180.0, 180.0);
    uniform_int_distribution<> batteryDist(0, 100);
    uniform_int_distribution<> speedDist(0, 200);
    uniform_int_distribution<> odoDist(50, 300);
    uniform_int_distribution<> timeDist(0, 100); 
    uniform_int_distribution<> statusDist(0, 2); 


    latitude = latDist(gen);
    longitude = lonDist(gen);
    batteryPercentage = batteryDist(gen);
    speed = speedDist(gen);
    odometerReading = odoDist(gen);
    long long timeStamp = timeDist(gen);
    if(statusDist(gen)==0) string engineStatus="On";
    if(statusDist(gen)==1) string engineStatus="Idle";
    if(statusDist(gen)==2) string engineStatus="Off";

    // Tracking stats
    int active = 0, inactive = 0;
    int battery = 0;
    long long fleetDistance = 0;

    battery += batteryPercentage;


    fleetDistance += odometerReading;

    //ALERT SYSTEM
    //Alert for battery and high speed
    alert(speed, batteryPercentage);
        

}

/*
    //Telemenary data DUMMY VALUES through input
    void telementaryData(){

        cout<<"Latitude: ";
        cin>>latitude;

        cout<<"Longitude: ";
        cin>>longitude;

        cout<<"Battery Level: ";
        cin>>batteryPercentage;

        //data to calcuate the average battery percenatge
        battery+=batteryPercentage;

        cout<<"Engine Status(On/Off/Idle): ";
        cin>>engineStatus;

        //to print the count of active and inactive vehicles
        if(engineStatus=="On"){  
            active++;
        }else if(engineStatus=="Off"){
            inactive++;
        }

        cout<<"Speed: ";
        cin>>speed;

        cout<<"Odometer Reading: ";
        cin>>odometerReading;

        //for calculating the distance travelled by the fleet
        fleetDistance+=odometerReading;

        cout<<"Time Stamp: ";
        cin>>timeStamp;

        //ALERT SYSTEM
        //Alert for battery and high speed
        if(battery<=15){
            cout<<"ALERT: Low Battery"<<endl;
        }

        if(speed>50){
            cout<<"ALERT: Over-speeding | speed=50Km/hr"<<endl;
        }

}

*/

    //To receive telementary data
    //to get the coordinates of that vehicle
    void getlocation(){
        cout<<"latitude: "<<latitude<<endl;
        cout<<"longitude: "<<longitude<<endl;
    }
    //to get the bettery percenatge
    void getbattery(){
        cout<<"Battery Percentage: "<<batteryPercentage<<endl;
    }
    //to get the engine status
    void getEngineStatus(){
        cout<<"Engine Status: "<<engineStatus<<endl;
    }
    //to get the speed of the vehicle
    void getSpeed(){
        cout<<"Speed: "<<speed<<endl;
    }
    //to get the odometer reading of the vehicle
    void getOdometerReading(){
        cout<<"Odometer Reading: "<<odometerReading<<endl;
    }
    
    

//To extract information

    //info of vehicle(General Details)
    void generalInfo(){     
        cout<<"Vehicle Identification Number: "<<VIN<<endl;
        cout<<"Manufacturer: "<<Manufacturer<<endl;
        cout<<"Model: "<<Model<<endl;
        cout<<"fleet type: "<<fleetType<<endl;
        cout<<"Fleet ID: "<<fleetId<<endl;
        cout<<"Status: "<<status<<endl;
        cout<<"Owner: "<<owner<<endl;
        
    }

    //info of telementary data
    void telemenatryInfo(){
        cout<<"Latitude: "<<latitude<<endl;
        cout<<"Longitude: "<<longitude<<endl;
        cout<<"Battery Level: "<<batteryPercentage<<endl;
        cout<<"Engine Status(On/Off/Idle): "<<engineStatus<<endl;
        cout<<"Speed: "<<speed<<endl;
        cout<<"Odometer Reading: "<<odometerReading<<endl;
        cout<<"Time Stamp: "<<timeStamp<<endl;
    }
};

//Basic Analytics on the basis of DUMMY Data (taken through input)

    //total active vehicles in the fleet
    void activeVehicles(){
        cout<<"Total Active Vehicles: "<<active<<endl;;
    }

    //total inactive vehicles in the fleet
    void inactiveVehicles(){
        cout<<"Total Inactive Vehicles: "<<inactive<<endl;;
    }

    //average battery of vehicles in the fleet
    void averageBattery(){
        cout<<"Average Battery level: "<<battery/countt<<endl;
    }

    //total distance travelled by the vehicles in the fleet
    void totalDistance(){
        cout<<"Total distance travelled by the fleet: "<<fleetDistance<<endl;
    }

int main(){
    Vehicle v1;
    Vehicle v2;

    cout<<"Creating vehicle 1";
    v1.create(123, "Tesla", "Ev101", "personal", 321, "Active", "Kejal");
    cout<<endl;

    cout<<"Enter Info for Vehicle 2"<<endl;;
    v2.create();
    cout<<endl;

    cout<<"Vehicle 1 telementary data"<<endl;
    v1.telementaryData();
    cout<<endl;

    cout<<"Vehicle 1 general information"<<endl;
    v1.generalInfo();
    cout<<endl;

    cout<<"Vehicle 1 telementary info"<<endl;
    v1.telemenatryInfo();
    cout<<endl;


    activeVehicles();
    inactiveVehicles();
    averageBattery();
    totalDistance();

    v1.getbattery();
    v1.getEngineStatus();
    v1.getlocation();
    v1.getOdometerReading();
    v1.getSpeed();
    
}

/*
OUTPUT 

Vehicle Identification Number: 456
Manufacturer: Honda
Model: H789
fleet type: Corporate
Fleet ID: 654
Status: Active
Owner: Jiyana
Latitude: 20
Longitude: 120
Battery Level: 10
Engine Status(On/Off/Idle): On
Speed: 80
Odometer Reading: 150
Time Stamp: 100
ALERT: Low Battery
ALERT: Over-speeding | speed=50Km/hr
Vehicle Identification Number: 123
Manufacturer: Tesla
Model: Ev101
fleet type: personal
Fleet ID: 321
Status: Active
Owner: Kejal
Latitude: 20
Longitude: 120
Battery Level: 10
Engine Status(On/Off/Idle): On
Speed: 80
Odometer Reading: 150
Time Stamp: 100
Total Active Vehicles: 1
Total Inactive Vehicles: 0
Average Battery level: 10
Total distance travelled by the fleet: 150
Battery Percentage: 10
Engine Status: On
latitude: 20
longitude: 120
Odometer Reading: 150
Speed: 80
*/

/*
OUPUT using random values
Creating vehicle 1
Enter Info for Vehicle 2
Vehicle Identification Number: 456
Manufacturer: Honda
Model: H984
fleet type(Corporate, Rental, Personal): Rental
Fleet ID: 654
Status(Active, Inactive): Active
Owner: Jiya

Vehicle 1 telementary data

Vehicle 1 general information
Vehicle Identification Number: 123
Manufacturer: Tesla
Model: Ev101
fleet type: personal
Fleet ID: 321
Status: Active
Owner: Kejal

Vehicle 1 telementary info
Latitude: 0
Longitude: 0
Battery Level: 0
Engine Status(On/Off/Idle): 
Speed: 1826763056
Odometer Reading: 1
Time Stamp: 50288912

Total Active Vehicles: 1
Total Inactive Vehicles: 0
Average Battery level: 0
Total distance travelled by the fleet: 0
Battery Percentage: 0
Engine Status: 
latitude: 0
longitude: 0
Odometer Reading: 1
Speed: 1826763056
*/
