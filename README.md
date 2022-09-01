# SZMatrix
Space-partitioning data structure to improve queries for clustered points in 2D space

I had this idea of efficient storage of geographic points. Essentially, we have a rectangular area in 2D space split into 4 equal parts. We then add points to this area. When the number of points in the rectangle becomes too large, we split, or 'balance' the data structure, by duplicating the data structure 4 times. In this way, we can increase the memory allocated to certain regions, allowing for appropriate representation of clustered points.
