set term png
set output "plot.png"
set grid
plot    "data.d" using 2:3 with lines title "Body 1",\
        "data.d" using 4:5 with lines title "Body 2"
