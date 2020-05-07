#include<bits/stdc++.h>
using namespace std;
std::string execute(std::string appID) 
{
    system(("node apple_app_store_reviews.js "+ appID  + " > result_reviews_2.txt 2>&1").c_str());
 
    std::ifstream ifs("result_reviews_2.txt");
    std::string ret{ std::istreambuf_iterator<char>(ifs), std::istreambuf_iterator<char>() };
    ifs.close();

    if (std::remove("result_reviews_2.txt") != 0) 
    {
        perror("Error deleting temporary file");
    }    
    return ret;
}

void execute_py() 
{
    string empty = "";
    system(("python senti_score_apple.py "+ empty  + " > python_score_2.txt 2>&1").c_str());
}

int main( int argc ,char * argv[] )
{
    ofstream app_details;
    ofstream final_score;
    final_score.open("apple_senti.txt");
    ifstream app_list;
    string senti_type = argv[1];
    app_list.open("output_2.txt");
    vector<string> appIdList;
    multimap<double, string, greater<double>> umap; 

    string line;
    while ( getline (app_list,line) )
    {
        appIdList.push_back(line);
    }
    app_list.close();
    // cout<<"app id = "<<line<<endl;
    int line_number=0;

    for(int k=0; k<appIdList.size(); k++)
    {
        string indivisual_app_details;
        indivisual_app_details=execute(appIdList[k]);  
        app_details.open("output_apple_text_reviews.txt");

        string tt="'";

        int n=indivisual_app_details.size();
        int total_reviews=0;
        string s=indivisual_app_details;
        for(int i=0;i< n-3;i++)
        {
            if(total_reviews>=100)
                break;
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
                total_reviews++;
            }
        }
        app_details.close();

        execute_py();
        string scores;
        
        ifstream pyfile;
        pyfile.open("python_score_2.txt");

        int pos_score = 0, neg_score =0, temp_score, count=0;
        string temp_str;
        while(getline(pyfile, scores))
        {
            if(scores.size() >= 4)
            {
                temp_str = "";
                temp_str += scores[0];
                temp_score = stoi(temp_str);
                pos_score += temp_score;

                temp_str = "";
                temp_str += scores[3];
                temp_score = stoi(temp_str);
                neg_score += (-1*temp_score);

                count++;
            }
        }

        double pos, neg;
        if(count == 0)
        {
            pos = 1.0;
            neg = -1.0;
        }
        else
        {
            pos = (double)pos_score/count;
            neg = (double)neg_score/count;
        }

        cout << pos << endl;
        cout << neg << endl;
        neg = -1.0*neg;

        if(senti_type == "positive")
        {
            umap.insert(make_pair(pos, appIdList[k]));
        }
        else
        {
            umap.insert(make_pair(neg, appIdList[k]));
        }
        pyfile.close();
        // string scoreline;
        // while ( getline (app_list,scoreline) )
        // {
        //  appIdList.push_back(line);
        // }
        // app_list.close();
        // cout<<"total_reviews= "<<total_reviews<<endl;
    }

    multimap<double,string> :: iterator it;
    for(it=umap.begin(); it!=umap.end(); it++)
    {
        cout << (*it).second << endl;
        final_score << (*it).second << endl;
    }
    final_score.close();
}