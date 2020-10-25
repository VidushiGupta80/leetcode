//Employee Importance -> 07/13/2020 12:50
/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
private:
    int BFS(int id, vector<Employee*>& employees)
    {
        
        Employee* temp;
        for(int i = 0; i < employees.size(); i++)
        {
            if(employees[i]->id == id)
            {
                temp = employees[i];
                break;
            }
        }
        
        if(temp->subordinates.size() == 0)
            return temp->importance;
        
        int ans = 0;
        for(int i = 0; i < temp->subordinates.size(); i++)
        {
            ans += BFS(temp->subordinates[i], employees);
        }
         return temp->importance + ans;
    }
    
public:
    int getImportance(vector<Employee*> employees, int id) {
        
        
        int ans = 0;
        ans += BFS(id, employees);
        return ans;
    }
};
