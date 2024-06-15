Hello. This simple consol app will help you with topological sort.
All you need to do is:
1) create a file with following format:
   N (int) - amount of nodes
   M (int) - amount of edges
   Node1 (any) - name of node 1
   Node2 (any) - name of node 2
   ... - N lines
   Node5 (any, expample) - name of node, witch first edge goes FROM
   Node3 (any, example) - name of node, witch first edge goes TO
   Node8 (any, example) - name of node, witch second edge goes FROM
   Node1 (any, example) - name of node, witch second edge goes TO
   ... - M * 2 lines

    Ex:            
       4
       4
       Node1
       Node2                                                               
       Node3                                                                
       Node4                                                    Node1------->Node2                
       Node1                                                      ^            |
       Node2            <------- This graph looks like that:      |            |
       Node2                                                      |            |
       Node3                                                      |            V
       Node3                                                    Node4<-------Node3
       Node4                                                                     
       Node4
       Node1

3) start an app. Please, write the name of your file as an argument in command line
   Ex: ./main filename.txt


   
