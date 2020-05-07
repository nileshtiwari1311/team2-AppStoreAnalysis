#include<bits/stdc++.h>
using namespace std;
int main()
{
	ifstream infile;
	infile.open("input_2.txt");
	ofstream outfile;
	outfile.open("single_app_details_2.txt");
	string line;
	int turn=0;
	std::vector<string> det;
	string s_c="'";
	char special_char=s_c[0];
	while(getline(infile,line))
	{
        if(turn==0)
        {
            int n=line.size();
            for(int i=0;i<=n-2;i++)
            {
                string temp;
                for(int j=0;j<2;j++)
                    temp.push_back(line[i+j]);
                if(temp=="id")
                {
                    string id;
                    for(int j=i+4;j<n;j++)
                    {
                        if(line[j]==',')
                            break;
                        id.push_back(line[j]);
                    }
                    string header="https://apps.apple.com/in/app/id";
                    header.append(id);
                    det.push_back(header);
                    turn=1;
                    break;
                }
            }
        }   
		else if(turn==1)
		{
			int n=line.size();
            for(int i=0;i<=n-5;i++)
            {
                string temp;
                for(int j=0;j<5;j++)
                    temp.push_back(line[i+j]);
                if(temp=="title")
                {
                    string title;
                    for(int j=i+8;j<n;j++)
                    {
                    	if(line[j]==special_char)
                    		break;
                    	title.push_back(line[j]);
                    }
                    det.push_back(title);
                    //cout<<title<<endl;
                    turn=2;
                    break;
                }
            }
		}
        else if(turn==2)
        {
            int n=line.size();
            for(int i=0;i<=n-4;i++)
            {
                string temp;
                for(int j=0;j<4;j++)
                    temp.push_back(line[i+j]);
                if(temp=="size")
                {
                    string size;
                    for(int j=i+7;j<n;j++)
                    {
                        if(line[j]==special_char)
                            break;
                        size.push_back(line[j]);
                    }
                    int app_size = stoi(size);
                    app_size /= (1048576);
                    size = to_string(app_size);
                    size += "M";
                    det.push_back(size);
                    turn=3;
                    break;
                }
            }
        }        
        else if(turn==3)
        {
            int n=line.size();
            for(int i=0;i<=n-17;i++)
            {
                string temp;
                for(int j=0;j<17;j++)
                    temp.push_back(line[i+j]);
                if(temp=="requiredOsVersion")
                {
                    string requiredOsVersion;
                    for(int j=i+20;j<n;j++)
                    {
                        if(line[j]==special_char)
                            break;
                        requiredOsVersion.push_back(line[j]);
                    }
                    det.push_back(requiredOsVersion);
                    turn=4;
                    break;
                }
            }
        }     
        else if(turn==4)
        {
            int n=line.size();
            for(int i=0;i<=n-8;i++)
            {
                string temp;
                for(int j=0;j<8;j++)
                    temp.push_back(line[i+j]);
                if(temp=="released")
                {
                    string released;
                    for(int j=i+11;j<n;j++)
                    {
                        if(line[j]==special_char)
                            break;
                        released.push_back(line[j]);
                    }
                    det.push_back(released);
                    turn=5;
                    break;
                }
            }
        }
        else if(turn==5)
        {
            int n=line.size();
            for(int i=0;i<=n-7;i++)
            {
                string temp;
                for(int j=0;j<7;j++)
                    temp.push_back(line[i+j]);
                if(temp=="updated")
                {
                    string updated;
                    for(int j=i+10;j<n;j++)
                    {
                        if(line[j]==special_char)
                            break;
                        updated.push_back(line[j]);
                    }
                    det.push_back(updated);
                    turn=6;
                    break;
                }
            }
        }
        else if(turn==6)
        {
            int n=line.size();
            for(int i=0;i<=n-5;i++)
            {
                string temp;
                for(int j=0;j<5;j++)
                    temp.push_back(line[i+j]);
                if(temp=="price")
                {
                    string price;
                    for(int j=i+7;j<n;j++)
                    {
                        if(line[j]==',')
                            break;
                        price.push_back(line[j]);
                    }
                    det.push_back(price);
                    turn=7;
                    break;
                }
            }
        }
        else if(turn==7)
        {
            int n=line.size();
            for(int i=0;i<=n-9;i++)
            {
                string temp;
                for(int j=0;j<9;j++)
                    temp.push_back(line[i+j]);
                if(temp=="developer" && line[i+9]!='I')
                {
                    string developer;
                    for(int j=i+12;j<n;j++)
                    {
                        if(line[j]==special_char)
                            break;
                        developer.push_back(line[j]);
                    }
                    det.push_back(developer);
                    turn=8;
                    break;
                }
            }
        }
		else if(turn==8)
		{
			int n=line.size();
            for(int i=0;i<=n-5;i++)
            {
                string temp;
                for(int j=0;j<5;j++)
                    temp.push_back(line[i+j]);
                if(temp=="score")
                {
                    string score;
                    for(int j=i+7;j<n;j++)
                    {
                    	if(line[j]==',')
                    		break;
                    	score.push_back(line[j]);
                    }
                    det.push_back(score);
                    turn=9;
                    break;
                }
            }
		}
		else if(turn==9)
		{
			int n=line.size();
            for(int i=0;i<=n-7;i++)
            {
                string temp;
                for(int j=0;j<7;j++)
                    temp.push_back(line[i+j]);
                if(temp=="reviews")
                {
                    string reviews;
                    for(int j=i+9;j<n;j++)
                    {
                    	if(line[j]==',')
                    		break;
                    	reviews.push_back(line[j]);
                    }
                    det.push_back(reviews);
                    turn=10;
                    break;
                }
            }
		}	

		
		
													
	}
    std::vector<string> det_2(det.size());
    det_2[0]=det[1];
    det_2[1]=det[8];
    det_2[2]=det[9];
    det_2[3]=det[6];
    det_2[4]=det[2];
    det_2[5]=det[3];
    det_2[6]=det[7];
    det_2[7]=det[4];
    det_2[8]=det[5];
    det_2[9]=det[0];
	for(int i=0;i<det.size();i++)
	{
        if(i!=det.size()-1)
		  outfile<<det_2[i]<<endl;
        else
            outfile<<det_2[i];
		//cout<<"ith is |"<<det[i]<<"|"<<endl;
	}
}