#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Schedule
{
    int ind;
    int start;
    int end;
    char assigned_to;
    Schedule(): start(0), end(0), assigned_to('n') {}
    Schedule(int p_ind, int p_start, int p_end): ind(p_ind), start(p_start), end(p_end), assigned_to('n') {}
    bool overlap(Schedule other_schedule)
    {
        if(this->end <= other_schedule.start)
        {
            return false;
        }
        else if (this->start >= other_schedule.end)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};

struct ScheduleOverlap
{
    Schedule a;
    Schedule b;

    ScheduleOverlap(Schedule p_a, Schedule p_b): a(p_a), b(p_b) {}
    bool is_triple_intersect(Schedule other_schedule)
    {
        if(other_schedule.ind == a.ind || other_schedule.ind == b.ind)
        {
            return false;
        }
        else
        {
            if(other_schedule.overlap(this->a) && other_schedule.overlap(this->b))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
};

bool sort_schedule_starts(pair<int, int> start_ind_pair_a, pair<int, int> start_ind_pair_b)
{
    return start_ind_pair_a.second < start_ind_pair_b.second; 
}

int main()
{
    int t = 0;
    cin >> t;
    int case_no = 0;
    while(t--)
    {
        case_no++;
        int n = 0;
        cin >> n;
        
        Schedule schedules[n];
        pair<int, int> start_ind_pairs[n];

        for(int i = 0; i < n; i++)
        {
            int start = 0, end = 0;
            cin >> start >> end;

            schedules[i] = Schedule(i, start, end);
            start_ind_pairs[i] = make_pair(i, start);
        }

        vector< ScheduleOverlap > overlapping_schedules;

        for(int i = 0; i < n; i++)
        {
            for(int j = (i + 1); j < n; j++)
            {
                if(schedules[i].overlap(schedules[j]))
                {
                    overlapping_schedules.push_back(ScheduleOverlap(schedules[i], schedules[j]));
                }
            }
        }

        bool is_soln_possible = true;

        for(int i = 0; i < overlapping_schedules.size(); i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(overlapping_schedules[i].is_triple_intersect(schedules[j]))
                {
                    is_soln_possible = false;
                    break;
                }
            }
        }

        string result = "";

        if(is_soln_possible)
        {
            for(int i = 0; i < n; i++)
            {
                bool overlap_set = false;
                for(int j = 0; j < i; j++)
                {
                    if(schedules[i].overlap(schedules[j]))
                    {
                        overlap_set = true;
                        if(schedules[j].assigned_to == 'C')
                        {
                            schedules[i].assigned_to = 'J';
                        }
                        else
                        {
                            schedules[i].assigned_to = 'C';
                        }
                        break;
                    }
                }
                if(!overlap_set)
                {
                    schedules[i].assigned_to = 'C';
                }
            }
            for(int i = 0; i < n; i++)
            {
                result += schedules[i].assigned_to;
            }
        }
        else
        {
            result = "IMPOSSIBLE";
        }

        cout << "Case #" << case_no << ": " << result << endl;
    }
}
