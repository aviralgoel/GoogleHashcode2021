/* Hashcode 2021 - Empty Template
Team 1024
*/

#include <bits/stdc++.h>
using namespace std;



struct pizza {

    int id; //pizza id/no.
    int noOfIng; //number of ingredients in the pizza
    vector<string> listOfIng; //list of ingredients

};


int M, T2, T3, T4;
vector<pizza> hub;
// Data input function
// Data Input function
void read(string input_file) {

  //open the file
  ifstream fin(input_file);
  //input from file
  fin>>M>>T2>>T3>>T4;

  for(int i = 1 ; i <= M ; i++)
  {
      pizza temp_pizza;
      temp_pizza.id = i;
      int l;
      fin>>l;
      temp_pizza.noOfIng = l;
      for(int j = 0 ; j < l ; j++)
      {
          string ing;
          fin>>ing;
          temp_pizza.listOfIng.push_back(ing);
      }

      hub.push_back(temp_pizza);
  }



}

void write(string output_file) {

    ofstream outfile(output_file);
    outfile<<oplib.size()<<endl;
    //For each selected library
    for(int i = 0; i < oplib.size(); i++) {
        //Display the no. of books which that library sent
        outfile<<oplib[i].id<<" "<<oplib[i].selected_bids.size()<<endl;

        // Display individual book IDs that were sent to sign up
        for(int j = oplib[i].selected_bids.size() - 1; j >= 0; j--) {
            outfile<<oplib[i].selected_bids[j]<<" ";
        }
        outfile<<endl;
    }
}



void solve()
{
    //sort to rank the libraries with least sign up time first. Quicker sign ups implies they can send more in the long run.
    sort(vp_time.begin(), vp_time.end());

    //Count how many days are left for the whole process, and how many books are left overall.
    int days_remaining = D;
    int books_remaining = B;

    // For every library there is.
    for(int i = 0; i < L; i++)
    {
        //Is there enough time left to sign up this library, if not, return

        int lib_id = vp_time[i].second;
        //cout<<"Lib: "<<i<<" "<<lib_id<<" "<<endl;
        if(lib[lib_id].t > days_remaining) {
            return;
        }

        //If there is time left, then sign this up and calculate how much score will be yield from this library until the end
        days_remaining -= lib[lib_id].t;
        //cout<<"days remaining "<<days_remaining<<endl;


        lib[lib_id].pdays = days_remaining; // No. of days for this library to send books

        // no. of books it can send, either depending on days remaining or all of it's books, if books are less
        lib[lib_id].pbooks = min(days_remaining * lib[lib_id].m, lib[lib_id].n);

        //For all the books in this particular library
        for(int j = 0; j < lib[lib_id].bids.size(); j++) {
            //cout<<j<<endl;
            int book_id = lib[lib_id].vp_score_bid[j].second;
            //cout<<book_id;
            //if the library has that certain book, add it to the book which will be sent
            if(!b_bool[book_id]) {
                b_bool[book_id] = true;
                lib[lib_id].selected_bids.push_back(book_id);
                books_remaining--;
            }
            //Stop if all books are over
            if(lib[lib_id].selected_bids.size() == lib[lib_id].pbooks) {
                break;
            }
        }
        //cout<<"books remaining "<<books_remaining<<endl;

        //When no books are left
        if(lib[lib_id].selected_bids.size() == 0)
        {
            days_remaining += lib[lib_id].t;
        }
        else
        {
            //cout<<"Lib: "<<i<<" added"<<endl;
            oplib.push_back(lib[lib_id]);
        }

        if(books_remaining == 0)
        {
            return;
        }
    }

}




int main()
{
    string INPUTS[] = {"a_example.in", "b_little_bit_of_everything.in", "c_many_ingredients.in", "d_many_pizzas.in", "e_many_teams.in"};
    string OUTPUTS[] = {"a_example.out", "b_little_bit_of_everything.out", "c_many_ingredients.out", "d_many_pizzas.out", "e_many_teams.out"};
    //For all input files
    for(int x = 0; x < 5; x++)
    {
        // Read, Solve and Display
         read(INPUTS[x]);
        cout<<"read done"<<endl;

        solve();
        cout<<"solve done"<<endl;

        write(OUTPUTS[x]);
        cout<<"write done"<<endl;;

    }

    cout << hub.size();
}
