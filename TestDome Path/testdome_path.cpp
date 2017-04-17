#include <iostream>
#include <string>
#include <stack>
#include <stdexcept>

using namespace std;
class Path
{
public:

   Path(std::string path)
   {
      currentPath = path;
   }

   std::string getPath() const
   {
      return currentPath;
   }

   Path cd(std::string newPath) const
   {      
       Path p = *this;
       // Checking if newPath is the root directory
       if (newPath.size()==1 && newPath[0]=='/')
       {
           p.currentPath='/';
           return p;     
       }
       // Stack to keep track of the folder path
       stack <string> s;	  
       string finalPath,s1,s2;	         	  
       char* ptr = &(p.currentPath[0]);      
       //pushing currentPath onto stack		
       while (*ptr)		                    
       {               
           if (*ptr=='/')			
           {           
               if (!s1.empty())               
                   s.push(s1);                   
               s1.clear();				
           }           
           else            
           {           
               s1+=*ptr;                                           
           }			
           ptr++;			
       }
       // Pushing the last remaining folder if exists in the string s1
       if (!s1.empty())       
           s.push(s1);		                            
       ptr = &newPath[0];
       // Parsing the newPath and making changes to the stack accordingly
       while (*ptr) 
       {
           //Append '.' to the string if character is '.'
           if (*ptr == '.')             
           {     
               s2 += *ptr;
           }
           // Push the string onto the stack and clear it if character is '/'.
           else if (*ptr == '/')			
           {            
               if (!s2.empty())             
                   s.push(s2);			
               s2.clear();			
           }
           //Append characters to the string till we encounter a '/'
           else if (isalpha(*ptr))             
           {			
               s2+=*ptr;			
           }
           
           //Check if the string test contains "..", then pop an element from the stack and clear the string
           if (s2 == "..") 
           {                
               if (!s.empty())				
                   s.pop();				
               s2.clear();			
           }			
           ptr++;		
       }
       // Pushing the last remaining folder if exists in the string s2
       if (!s2.empty())
           s.push(s2);
       // Creating the finalPath based on the contents of the stack
       if (!s.empty())
       {       
           while (!s.empty())		
           {			
               finalPath.insert(0,s.top());			
               finalPath.insert(finalPath.begin(), '/');			
               s.pop();		
           }
       }
       else
       {
           finalPath+='/';
       }        	
       p.currentPath = finalPath;       
       return p;      	
   }
private:	
    std::string currentPath;
};


#ifndef RunTests
int main()
{
    Path path("/a/b/folder1/d");
    std::cout << path.cd("s/f").getPath();
}
#endif
