# Google Hashcode 2021 - Traffic Problem
 
 This was the submission of our team of 4 people for the Google Hashcode 2021 hosted online.
 We scored an overall rank of #2016 and #2 in the nation.
 (Better than our rank of last year, Yay!)
 
 # Traffic Signalling: Task
 > Given the description of a city plan and planned paths for all cars i n that city,
optimize the schedule of traffic l ights to minimize the total amount of time spent i n
traffic, and help as many cars as possible reach their destination before a given
deadline [simulation].

In a nutshell, we had a list of intersections (with traffic lights installed) and the names of the streets running between those intersections as well as the length of the streets. We also had a list of cars with their predetermined paths that they had to travel to complete their journey. Our aim was to maximize the number of cars that complete their entire journey, in a fixed amount of total time by determining the schedule the traffic lights must follow at each intersection. 
For a more formal description, check the official problem statement [here.](https://github.com/aviralgoel/GoogleHashcode2021/blob/main/GoogleHashcode2021/hashcode_2021_online_qualifications.pdf)


# Solution Approach
 
 From what we can understand within the given 5 hours time frame of the competition, we had set the following aims.
 Objective:
 1. Store all the information (total simulation time, number of intersections, number of streets etc.) (Done)
 2. Store all the information about each car and each street (Done)
 3. Optimize in such a way that you can figure out, which intersection would likely follow heavy traffic and which would not. (Sort of Done)
 4. Further Optimize (or rank) the streets according to their length and how frequently were they visited. (Partially Done)
 5. Look for further optimizations which can make determining an ideal time frame for green and red duration of traffic light. (Somewhat done but solution is dumb)
 6. Further optimization according to test cases. (NOT DONE)
    
## Takeaways:
 1. We should have been a little more prepared for the large sets of the data.
 2. We should have taken advanatge of the visualize option in the Judge System (Especially for test case f.)
 3. We should have tried a combination of (random+sort) on the data set. 
 4. We should have tried to normalize our metric variable.
 5. Obviously, thought of better approaches, perhaps, graph or advance set theory. 
