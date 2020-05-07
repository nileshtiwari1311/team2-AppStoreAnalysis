#include<bits/stdc++.h>
using namespace std;
std::string execute(string category, string country, string collection ) 
{

    system(("node apple_downloads.js "+ country +" " + category +  +" " + collection + " > result_no_of_downloads_2.txt 2>&1").c_str());
 
    std::ifstream ifs("result_no_of_downloads_2.txt");
    std::string ret{ std::istreambuf_iterator<char>(ifs), std::istreambuf_iterator<char>() };
    ifs.close();

    if (std::remove("result_no_of_downloads_2.txt") != 0) 
    {
        perror("Error deleting temporary file");
    }    
    return ret;
}
bool comp( tuple<string , long long> &a, tuple<string, long long> &b )
{
	if( get<1>(a) > get<1>(b) )
		return 1;
	return 0;
}
int main( int argc, char * argv[] )
{
	int z1=0;
	vector< tuple< string ,long long > > allapps;
	ofstream out_file;
	out_file.open( "apple_output_sort_by_downloads.txt" );
	string country=argv[1];
    string category=argv[2];
    string collection=argv[3];
    string indivisual_app_details;
    indivisual_app_details=execute(category,country,collection);  
    cout<<indivisual_app_details<<endl;
    int n=indivisual_app_details.size();
    string f2="reviews: ";
    string f1="id: ";
    string tt="'";
    char to_break=tt[0];
    int found1=0,found2=0;

    string tempid,tempdownloads;
    for(int i=0;i<n-9;i++)
    {
        if(found1==0)
        {
            string temp;
            for(int j=i;j< i+4;j++ )
                temp.push_back( indivisual_app_details[j] );      
            if(temp==f1)
            {
                int j=i+4;
                while( j<n && indivisual_app_details[j]!=',' )
                {
                    tempid.push_back( indivisual_app_details[j] );
                    j++;
                }
                found1=1;               
            }          
        }
        else if(found2==0)
        {
            string temp;
            for(int j=i;j< i+9;j++ )
                temp.push_back( indivisual_app_details[j] );
            if(temp==f2)
            {
                int j=i+9;
                while( j<n && indivisual_app_details[j]!=',' )
                {
                    tempdownloads.push_back( indivisual_app_details[j] );
                    j++;
                }
                found1=0;
                allapps.push_back( make_tuple( tempid, stoll( tempdownloads ) ) );
                tempid="";
                tempdownloads="";                
            }            
        }
    }
    sort( allapps.begin(),allapps.end(),comp );
    for(int i=0;i<allapps.size();i++)
    {
    	out_file<< get<0>(allapps[i])<<endl;
    	cout<< get<0>(allapps[i])<<endl;
    	cout<<get<1>(allapps[i])<<endl;
    }
}