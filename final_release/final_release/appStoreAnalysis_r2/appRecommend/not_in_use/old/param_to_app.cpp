#include<bits/stdc++.h>
using namespace std;
std::string execute(std::string appID) 
{
    system(("node google_play_store_rating.js "+ appID + " > result_recent_1.txt 2>&1").c_str());
 
    std::ifstream ifs("result_recent_1.txt");
    std::string ret{ std::istreambuf_iterator<char>(ifs), std::istreambuf_iterator<char>() };
    ifs.close();

    if (std::remove("result_recent_1.txt") != 0) 
    {
        perror("Error deleting temporary file");
    }    
    return ret;
}
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
    ofstream out_file, out_file1;
    out_file.open("output.txt");
    out_file1.open("output_recent.txt");
    string min_score=argv[1];
    string status_free=argv[2];
    int sort_by=stoi(argv[3]);
    for(int i=0;i<status_free.size();i++)
    {
        status_free[i]=tolower(status_free[i]);
    }
    float min_score_1=stof(min_score);
    ifstream inFile;
    inFile.open("test.txt");
    string line;
    string id;
    string score;
    string free;
    int found_id=0,found_score=0,found_free=0;
    string tt="'";
    char y=tt[0];
    while(getline(inFile,line))
    {
        //cout<<"before first if"<<endl;
        if(found_id==0)
        {
            int n=line.size();
            for(int i=0;i<=n-5;i++)
            {
                string temp;
                for(int j=0;j<5;j++)
                    temp.push_back(line[i+j]);
                if(temp=="appId")
                {
                    int start_index=i+5;
                    for(int j=i+5;j<n;j++)
                    {
                        if(line[j]==y)
                        {
                            break;
                        }
                        start_index++;
                    }
                    start_index++;
                    //cout<<start_index<<endl;
                    for(int j=start_index;j<n;j++)
                    {
                        if(line[j]==y)
                            break;
                        id.push_back(line[j]); 
                        //cout<<"line["<<j<<"] "<<line[j]<<endl;   
                    }
                    //cout<<"id ="<<id<<endl;                    
                    found_id=1;
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
                for(int j=0;j<9;j++)
                    temp.push_back(line[i+j]);
                if(temp=="scoreText")
                {
                    int start_index=i+9;
                    for(int j=i+9;j<n;j++)
                    {
                        if(line[j]==y)
                        {
                            break;
                        }
                        start_index++;
                    }
                    start_index++;
                    //cout<<start_index<<endl;
                    for(int j=start_index;j<n;j++)
                    {
                        if(line[j]==y)
                            break;
                        score.push_back(line[j]); 
                        //cout<<"line["<<j<<"] "<<line[j]<<endl;   
                    }
                    //cout<<"score ="<<score<<endl;                    
                    found_score=1;
                    break;
                }
            }
        }
        else if(found_free==0)
        {
            int n=line.size();
            for(int i=0;i<=n-9;i++)
            {
                string temp;
                for(int j=0;j<9;j++)
                    temp.push_back(line[i+j]);
                if(temp=="priceText")
                {
                    int start_index=i+9;
                    for(int j=i+9;j<n;j++)
                    {
                        if(line[j]==y)
                        {
                            break;
                        }
                        start_index++;
                    }
                    start_index++;
                    //cout<<start_index<<endl;
                    for(int j=start_index;j<n;j++)
                    {
                        if(line[j]==y)
                            break;
                        free.push_back(line[j]); 
                        //cout<<"line["<<j<<"] "<<line[j]<<endl;   
                    }
                    //cout<<"free ="<<free<<endl;                    
                    found_free=1;
                    break;
                }
            }
            //cout<<"before final if"<<endl;
            if(found_free==1)
            {
                float min_score_2=stof(score);
                for(int i=0;i<free.size();i++)
                {
                    free[i]=tolower(free[i]);
                }
                if(min_score_2 >= min_score_1 &&( (status_free=="free" && free=="free") ||  (status_free!="free" && free!="free")  ))
                {
                    //cout<<" checked id= "<<id<<endl;  
                    //out_file<<id<<endl;
                    //cout<<"before recent_reviews"<<endl;
                    string recent_reviews=execute(id);
                    //cout<<"command ling execute"<<endl;
                    int total_reviews=0;
                    float recent_rating=0;
                    //cout<<"  "<<recent_reviews<<endl;
                    for(int j=0;j<recent_reviews.size() -7 ;j++)
                    {
                        string sliding="";
                        for(int k=j;k<j+7;k++)
                        {
                            sliding.push_back(recent_reviews[k]);
                        }
                        if(sliding=="score: ")
                        {
                            total_reviews++;
                            recent_rating+= recent_reviews[j+7]-'0';
                            //cout<<recent_reviews[j+7];
                        }
                    }
                    if(total_reviews!=0)
                        recent_rating/=total_reviews;
                    all_apps.push_back( make_tuple(id,stof(score),recent_rating) );    
                    cout<<get<0>(all_apps[all_apps.size()-1])<<" "<<get<1>(all_apps[all_apps.size()-1])<<" "<<get<2>(all_apps[all_apps.size()-1])<<endl;

                }      
                found_id=0;
                found_score=0;
                found_free=0;
                id="";
                score="";
                free="";
            }

        }        
    }
    // if(sort_by==0)
    // {
       
    // }
    // else
    // {
        
    // }

    sort(all_apps.begin(),all_apps.end(),comp1);
    for(int i=0;i<all_apps.size();i++)
    {
        if(get<0>(all_apps[i]).size()!=0 )
            out_file<<get<0>(all_apps[i])<<endl;
    }

    sort(all_apps.begin(),all_apps.end(),comp2);
    for(int i=0;i<all_apps.size();i++)
    {
        if(get<0>(all_apps[i]).size()!=0 )
            out_file1<<get<0>(all_apps[i])<<endl;
    }
}