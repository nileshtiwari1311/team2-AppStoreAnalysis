#include<bits/stdc++.h>
using namespace std;
std::string execute(std::string appID) 
{
    system(("node apple.js "+ appID  + " > result_reviews_2.txt 2>&1").c_str());
 
    std::ifstream ifs("result_reviews_2.txt");
    std::string ret{ std::istreambuf_iterator<char>(ifs), std::istreambuf_iterator<char>() };
    ifs.close();

    if (std::remove("result_reviews_2.txt") != 0) 
    {
        perror("Error deleting temporary file");
    }    
    return ret;
}

int main( int argc ,char * argv[] )
{
    ofstream app_details;
    string appId = argv[1];

    int line_number=0;

    string indivisual_app_details;
    indivisual_app_details = execute(appId);  
    app_details.open("apple.txt");

    string tt="'";

    int n = indivisual_app_details.size();

    string s = indivisual_app_details;
    for(int i=0;i< n-3;i++)
    {
        string temp;
        temp.append( s.begin()+i,s.begin()+i+4 );
        if(temp== "text" )
        {
            int opens=0;
            string review;
            for(int j=i+5;j<n;j++)
            {
                if( s[j]== tt[0] )
                {
                    opens++;
                    if(opens==2)
                    {
                        i=j;
                        break;
                    }
                }
                else if(opens==1)
                {
                    review.push_back(s[j]);
                }    
            }
            app_details<<review<<endl<<endl;    
        }
    }
    app_details.close();
}