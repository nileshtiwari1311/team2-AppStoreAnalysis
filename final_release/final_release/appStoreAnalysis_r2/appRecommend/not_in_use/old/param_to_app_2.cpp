#include<bits/stdc++.h>
using namespace std;
bool comp1( tuple<string,float,float> f1,tuple<string,float,float> f2 )
{
    if( get<1>(f1) > get<1>(f2) )
        return 1;
    else
    {
        return 0;
    }
}
bool comp2( tuple<string,float,float> f1,tuple<string,float,float> f2 )
{
    if( get<2>(f1) > get<2>(f2) )
        return 1;
    else
    {
        return 0;
    }
}
int main(int argc, char * argv[])
{
    int z1=0;
    vector<tuple<string,float,float> > all_apps;
    ofstream out_file;
    out_file.open("output_2.txt");
    string min_score=argv[1];
    string status_free=argv[2];
    int sort_by=stoi(argv[3]);
    for(int i=0;i<status_free.size();i++)
    {
        status_free[i]=tolower(status_free[i]);
    }
    if(status_free=="free")
        status_free="true";
    else
    {
        status_free=="false";
    }
    float min_score_1=stof(min_score);
    ifstream inFile;
    inFile.open("test_2.txt");
    string line;
    string id;
    string score;
    string free;
    string current_score="";
    int found_id=0,found_score=0 , found_current_score=0,found_free=0;
    string tt="'";
    char y=tt[0];
    while(getline(inFile,line))
    {

        //cout<<"before first if"<<endl;
        if(found_id==0)
        {
            int n=line.size();
            for(int i=0;i<=n-4;i++)
            {
                string temp;
                for(int j=0;j<4;j++)
                    temp.push_back(line[i+j]);
                if(temp=="id: ")
                {
                    int start_index=i+4;
                    //cout<<start_index<<endl;
                    for(int j=start_index;j<n;j++)
                    {
                        if(line[j]==',')
                            break;
                        id.push_back(line[j]); 
                        //cout<<"line["<<j<<"] "<<line[j]<<endl;   
                    }
                    //cout<<"id ="<<id<<endl;                    
                    found_id=1;
                    break;
                }
            }
            //cout<<"id=" <<id<<endl;
        }
        else if(found_free==0)
        {
            int n=line.size();
            for(int i=0;i<=n-4;i++)
            {
                string temp;
                for(int j=0;j<4;j++)
                    temp.push_back(line[i+j]);
                if(temp=="free")
                {
                    if(line[i+6]=='t')
                        free="true";
                    else
                    {
                        free="false";
                    }                   
                    found_free=1;
                    break;
                }
            }
        }        
        else if(found_score==0)
        {
            int n=line.size();
            for(int i=0;i<=n-5;i++)
            {
                string temp;
                for(int j=0;j<5;j++)
                    temp.push_back(line[i+j]);
                if(temp=="score")
                {
                    for(int j=i+7;j<n;j++)
                    {
                        if(j==i+7 && ( line[j]<='0' || line[j] >='9' )   )
                            break;
                        if(line[j]!=',')
                            score.push_back(line[j]);
                    }
                    found_score=1;
                    break;
                }
            }
        }
        else if(found_current_score==0)
        {
            int n=line.size();
            for(int i=0;i<=n-19;i++)
            {
                string temp;
                for(int j=0;j<19;j++)
                    temp.push_back(line[i+j]);
                if(temp=="currentVersionScore")
                {
                    for(int j=i+21;j<n;j++)
                    {
                        if(j==i+21 && ( line[j]<='0' || line[j] >='9' )   )
                            break;                        
                        if(line[j]!=',')
                            current_score.push_back(line[j]);
                    }
                    //cout<<"current_score= "<<current_score<<endl;
                    found_current_score=1;
                    break;
                }
            }            
        }
        if(found_current_score==1)
        {
            //cout<<"score="<<score<<endl;
            //cout<<score<<endl;
            float min_score_2=0;
            if(score.size()!=0)
                min_score_2=stof(score);

            float current_score_in_float=min_score_2;

            if(current_score.size()!=0)
                current_score_in_float=stof(current_score);


            if(min_score_2 >= min_score_1 && ( (status_free=="true" && free=="true") || (status_free!="true" && free!="true") ))
            {
                all_apps.push_back( make_tuple(id, min_score_2 ,current_score_in_float) );    
                cout<<get<0>(all_apps[all_apps.size()-1])<<" "<<get<1>(all_apps[all_apps.size()-1])<<" "<<get<2>(all_apps[all_apps.size()-1])<<endl;
            }      
            found_id=0;
            found_score=0;
            found_free=0;
            found_current_score=0;
            id="";
            score="";
            free="";
            current_score="";
        }

    }     
    if(sort_by==0)
    {
        sort(all_apps.begin(),all_apps.end(),comp1);
    }
    else
    {
        sort(all_apps.begin(),all_apps.end(),comp2);
    }
    for(int i=0;i<all_apps.size();i++)
    {
        if(get<0>(all_apps[i]).size()!=0 )
            out_file<<get<0>(all_apps[i])<<endl;
    }
}