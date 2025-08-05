#include <iostream>
using namespace std;

class Vehicle{
    public:
    long long VIN; //Vehicle Identification Number
    string Manufacturer;
    string Model;
    string fleetType; //"Corporate", "Rental", "Personal"
    long long fleetId;
    string status; //Registration status: Active, Maintenance, Decommissioned
    string owner;
    long long distance; //to calculate distance travelled by the fleet


//Real-time Telemetry Data Processing
//Later Integrate APIs
    pair<long long, long long> coordinates;
    int batteryPercentage;
    string engineStatus; // On, Off, Idle
    int speed;
    int odometerReading;
    int timeStamp;
    int active=0;
    int inactive=0;
    int count=0; //total count of telemenatry data vehicles to calculate average bettery
    int battery=0; //sum of all battery percenatges


    void create(long long VIN_, string Manufacturer_, string Model_, string fleetType_, long long fleetId_, string status_, string owner_){
        VIN=VIN;
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


    //Telemenary data DUMMY VALUES through input
    void telementaryData(){

        cout<<"Latitude: ";
        cin>>coordinates.first;
        cout<<endl;

        cout<<"Longitude: ";
        cin>>coordinates.second;
        cout<<endl;

        cout<<"Battery Level: ";
        cin>>batteryPercentage;
        cout<<endl;

        //data to calcuate the average battery percenatge
        battery+=batteryPercentage;
        count++;

        cout<<"Engine Status(On/Off/Idle): ";
        cin>>engineStatus;
        cout<<endl;

        //to print the count of active and inactive vehicles
        if(engineStatus=="On"){  
            active++;
        }else if(engineStatus=="Off"){
            inactive++;
        }

        cout<<"Speed: ";
        cin>>speed;
        cout<<endl;

        cout<<"Odometer Reading: ";
        cin>>odometerReading;
        cout<<endl;
        //for calculating the distance travelled by the fleet
        distance+=odometerReading;

        cout<<"Time Stamp: ";
        cin>>timeStamp;
        cout<<endl;

        //ALERT SYSTEM
        //Alert for battery and high speed
        if(battery<=15){
            cout<<"ALERT: Low Battery"<<endl;
        }

        if(speed>50){
            cout<<"ALERT: Over-speeding | speed=50Km/hr"<<endl;
        }

}


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
        cout<<"Average Battery level: "<<battery/count<<endl;
    }

    //total distance travelled by the vehicles in the fleet
    void totalDistance(){
        cout<<"Total distance travelled by the fleet: "<<distance<<endl;
    }



    //To receive telementary data
    //to get the coordinates of that vehicle
    void getlocation(){
        cout<<"latitude: "<<coordinates.first<<endl;
        cout<<"longitude: "<<coordinates.second<<endl;
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
        cout<<"Latitude: "<<coordinates.first<<endl;
        cout<<"Longitude: "<<coordinates.second<<endl;
        cout<<"Battery Level: "<<batteryPercentage<<endl;
        cout<<"Engine Status(On/Off/Idle): "<<engineStatus<<endl;
        cout<<"Speed: "<<speed<<endl;
        cout<<"Odometer Reading: "<<odometerReading<<endl;
        cout<<"Time Stamp: "<<timeStamp<<endl;
    }
};

