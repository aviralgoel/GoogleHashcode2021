/* Google Hashcode 2021
Traffic Signaling
@author Aviral Goel, Basma Zubair, Urvashi Kishnani, Zunaira Zubair
Feb 2021
*/


#include <bits/stdc++.h>

using namespace std;

// variables to store, simulation time, number of intersections, number of streets,
// number of vehicles, number of bonus points per veheicle
int D, I, S, V, F;
// number of intersection for which we specify the schedule
int A;
//IDs of intersection that qualify to have either one or more of their traffic lights to be regulated.
vector<int> output_intersections;
//our mean of the metric (ranking function to determine streets are more likely to experience heavy traffic)
float mean_metric;

struct street {
    int id; //our own identifier for each street
    int B;
    int E;
    string name;
    int L;
    int popularity = 0;
    float metric;
};

struct car {
    int id; //our own identifier for each street
    int P;
    vector<string> street_names;
};

struct intersection {
    int id;
    int incoming_count = 0;
    vector<string> incoming_streets;
};

//one to one mapping between street IDs and street names
map<string, int> street_id;

//vectors to store all streets, cars and intersections.
vector<street> streets;
vector<car> cars;
vector<intersection> intersections;

// reading function to take the input
void read(char* input_file) {

    ifstream fin(input_file);
    fin>>D>>I>>S>>V>>F;

    for(int i = 0; i < I; i++) {
        intersection temp_intersection;
        temp_intersection.id = i;
        intersections.push_back(temp_intersection);
    }

    for(int i = 0; i < S; i++) {
        street temp_street;
        temp_street.id = i;
        fin>>temp_street.B>>temp_street.E>>temp_street.name>>temp_street.L;
        streets.push_back(temp_street);
        street_id.insert(pair<string, int>(temp_street.name, temp_street.id));
        intersections[temp_street.E].incoming_count++;
        intersections[temp_street.E].incoming_streets.push_back(temp_street.name);
    }

    for(int i = 0; i < V; i++) {
        car temp_car;
        temp_car.id = i;
        fin>>temp_car.P;
        for(int j = 0; j < temp_car.P; j++) {
            string _street_name;
            fin>>_street_name;
            int _street_id = street_id.at(_street_name);
            //cout<<"Car: "<<i<<endl;
            //cout<<"Street: "<<_street_id<<endl;
            streets[_street_id].popularity++;
            temp_car.street_names.push_back(_street_name);
        }
        cars.push_back(temp_car);
    }

    //cout<<intersections.size()<<endl;
    //cout<<streets.size()<<endl;
    //cout<<cars.size()<<endl;

}

void solve() {
    //number of intersections to deal with
    A = 0;

    // calculating metric for each street (METRIC = NUMBER OF CARS THAT WISH TO TRAVERSE THE STREET / DURATION OF STREET)
    for(int i = 0; i < streets.size(); i++) {
        streets[i].metric = streets[i].popularity * 1.0 / streets[i].L;
    }

    //Does this intersection has one incoming street?
    for(int i = 0; i < intersections.size(); i++) {
        if(intersections[i].incoming_count > 0) {
            A++;
            output_intersections.push_back(intersections[i].id);
        }
    }

    // Calculate the mean of the metric of all streets
    mean_metric = 0;
    for(int g = 0 ; g < streets.size(); g++)
    {
        mean_metric += streets[g].metric;
    }
    cout<<"Mean Metric: "<<mean_metric<<endl;
    mean_metric = mean_metric * 1.0 / streets.size();
    cout<<"Mean Metric: "<<mean_metric<<endl;
}

void write(char* output_file, int file_index) {

    ofstream outfile(output_file);
    outfile<<A<<endl;

    for(int i = 0; i < output_intersections.size(); i++) {

        int _id = output_intersections[i];
        outfile<<_id<<endl;

        int _output_intersection_count = 0;
        vector<string> _output_incoming_streets;
        _output_incoming_streets.clear();

        // Check which streets are to be visited by at least 1 car
        for(int j = 0; j < intersections[_id].incoming_streets.size(); j++) {
            int _street_id = street_id.at(intersections[_id].incoming_streets[j]);
            if(streets[_street_id].popularity != 0) {
                _output_intersection_count++;
                _output_incoming_streets.push_back(intersections[_id].incoming_streets[j]);
            }
        }

        //Randomn number as duration for traffic signal
        int below_metric=rand() % 15 + 1, above_metric= rand() % 30 + 8;;


        outfile<<_output_intersection_count<<endl;
        for(int j = 0; j < _output_intersection_count; j++) {
            int _street_id = street_id.at(_output_incoming_streets[j]);
            //Give a street more time if its busier than average
            if(streets[_street_id].metric >= mean_metric) {
                outfile<<_output_incoming_streets[j]<<" "<<above_metric<<"\n";
            }
            //Give it less time
            else
            {
                outfile<<_output_incoming_streets[j]<<" "<<below_metric<<"\n";
            }
        }
    }
}

int main()
{
    char* INPUTS[] = {"a.txt", "b.txt", "c.txt", "d.txt", "e.txt", "f.txt"};
    char* OUTPUTS[] = {"a.out", "b.out", "c.out", "d.out", "e.out", "f.out"};
    for(int x = 1; x < 2; x++) {
        // Resetting common variables between files
        intersections.clear();
        streets.clear();
        cars.clear();
        street_id.clear();

        output_intersections.clear();

        // Calling the read function
        read(INPUTS[x]);
        cout<<"read done"<<endl;

        // Calling the solve function
        solve();
        cout<<"solve done"<<endl;

        // Calling the write function
        write(OUTPUTS[x], x);
        cout<<"write done"<<endl;
    }
    return 0;
}
