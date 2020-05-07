#include<bits/stdc++.h>
using namespace std;
std::string execute(std::string appID) 
{
    system(("node apple_app_details_through_id.js "+ appID + " > result_recent_3.txt 2>&1").c_str());
 
    std::ifstream ifs("result_recent_3.txt");
    std::string ret{ std::istreambuf_iterator<char>(ifs), std::istreambuf_iterator<char>() };
    ifs.close();

    if (std::remove("result_recent_3.txt") != 0) 
    {
        perror("Error deleting temporary file");
    }    
    return ret;
}
int main()
{
    ifstream app_ids;
    ofstream app_details;
    app_details.open( "output_details_2.txt");
    app_ids.open("output_2.txt");
    string line;
    int line_number=0;
    while(getline(app_ids,line))
    {
        if(line.size()==0)
            break;
        if(line_number==0)
            app_details <<'['<<endl;
        if(line_number!=0)
            app_details << ','<<endl;    
        cout<<"line = "<<line<<endl;
        string indivisual_app_details=execute(line);  
        app_details<<indivisual_app_details<<endl;   
        line_number++;
    }
    if(line_number >0)
        app_details<< endl<<"]"<<endl;
    app_details.close();
    app_ids.close();    
}