
#include <iostream>
#include <stdlib.h>
using namespace std;

int active=0;
int inactive=0;
int countt=0; //total count of telemenatry data vehicles to calculate average bettery
int battery=0; //sum of all battery percenatges
long long fleetDistance; //to calculate distance travelled by the fleet

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
        cout<<endl;
  
        cout<<"Manufacturer: ";
        cin>>Manufacturer;
        cout<<endl;
      
        cout<<"Model: ";
        cin>>Model;
        cout<<endl;
      
        cout<<"fleet type: ";
        cin>>fleetType;
        cout<<endl;

        cout<<"Fleet ID: ";
        cin>>fleetId;
        cout<<endl;
  
        cout<<"Status: ";
        cin>>status;
        cout<<endl;

        cout<<"Owner: ";
        cin>>owner;
        cout<<endl;

    }
/*
//to generate dummy values of telementary data
    void telementaryData(){

}

*/
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

    v1.create(123, "Tesla", "Ev101", "personal", 321, "Active", "Kejal");
    v2.create();

    v1.telementaryData();

    v1.generalInfo();
    v1.telemenatryInfo();


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
