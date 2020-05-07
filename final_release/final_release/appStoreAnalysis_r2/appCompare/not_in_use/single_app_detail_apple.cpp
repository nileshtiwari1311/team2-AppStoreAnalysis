#include<bits/stdc++.h>
using namespace std;
int main()
{
	ifstream infile;
	infile.open("input.txt");
	ofstream outfile;
	outfile.open("single_app_details.txt");
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
                    turn=2;
                    break;
                }
            }
		}
		else if(turn==2)
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
                    turn=3;
                    break;
                }
            }
		}	
		else if(turn==3)
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
                    turn=4;
                    break;
                }
            }
		}
		else if(turn==4)
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
                    det.push_back(size);
                    turn=5;
                    break;
                }
            }
		}		
		else if(turn==5)
		{
			int n=line.size();
            for(int i=0;i<=n-18;i++)
            {
                string temp;
                for(int j=0;j<18;j++)
                    temp.push_back(line[i+j]);
                if(temp=="androidVersionText")
                {
                    string androidVersionText;
                    for(int j=i+21;j<n;j++)
                    {
                    	if(line[j]==special_char)
                    		break;
                    	androidVersionText.push_back(line[j]);
                    }
                    det.push_back(androidVersionText);
                    turn=6;
                    break;
                }
            }
		}
		else if(turn==6)
		{
			int n=line.size();
            for(int i=0;i<=n-9;i++)
            {
                string temp;
                for(int j=0;j<9;j++)
                    temp.push_back(line[i+j]);
                if(temp=="developer")
                {
                    string developer;
                    for(int j=i+12;j<n;j++)
                    {
                    	if(line[j]==special_char)
                    		break;
                    	developer.push_back(line[j]);
                    }
                    det.push_back(developer);
                    turn=7;
                    break;
                }
            }
		}
		else if(turn==7)
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
                    turn=8;
                    break;
                }
            }
		}
		else if(turn==8)
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
                    for(int j=i+9;j<n;j++)
                    {
                    	if(line[j]==',')
                    		break;
                    	updated.push_back(line[j]);
                    }
                    det.push_back(updated);
                    turn=9;
                    break;
                }
            }
		}		
		else if(turn==9)
		{
			int n=line.size();
            for(int i=0;i<=n-5;i++)
            {
                string temp;
                for(int j=0;j<5;j++)
                    temp.push_back(line[i+j]);
                if(temp=="appId")
                {
                    string appId;
                    for(int j=i+8;j<n;j++)
                    {
                    	if(line[j]==special_char)
                    		break;
                    	appId.push_back(line[j]);
                    }
                    string header="https://play.google.com/store/apps/details?id=";
                    header.append(appId);
                    det.push_back(header);
                    turn=10;
                    break;
                }
            }
		}														
	}
	for(int i=0;i<det.size();i++)
	{
		outfile<<det[i]<<endl;
		//cout<<"ith is |"<<det[i]<<"|"<<endl;
	}
}