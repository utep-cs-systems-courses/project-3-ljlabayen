# Project 3

This toy has 4 states that plays and draws simple shapes, tones and lights

# To load program:
~~~
$ cd /project
$ make load
~~~
# To clean
~~~
$ make clean
~~~
# Instructions/Switches

The buttons/interrupts are meant to finish the method calls (draw, lights
and/or sound) before being able to press another button.

`Button #1`
Pushing this button once will draw a pink triangle on the screen and play a
tone continuously and re-pressing the button will make the frequency lower in
three steps and will eventually turn off.

`Button #2`
Pushing this button will draw a yellow square then plays a small portion of
the "Baby Shark" song followed by a DIM slow blink from the red LED

`Button #3`
This button will draw a color changing triangle and plays the error tone

`Button #4`
Lastly, this button draws another yellow square then plays the last bit of the
Spongbob Squarepants theme song and will blink the red LED
