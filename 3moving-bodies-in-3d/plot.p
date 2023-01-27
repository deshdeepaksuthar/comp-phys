set term png
set output "plot.png"
set grid
# set view 0,0,1,1
splot   "data.d" using 2:3:4 with lines title "Body 1",\
        "data.d" using 5:6:7 with lines title "Body 2",\
        "data.d" using 8:9:10 with lines title "Body 3"
# plot   "data.d" using 2:3 with lines title "Body 1",\
#         "data.d" using 5:6 with lines title "Body 2",\
#         "data.d" using 8:9 with lines title "Body 3"
