# LLM-CPluPlus-Alpha
A very basic LLM written in C++ by me few months ago.

It can be trained on folder with .txt files and then run with created model folder. 

How does it work:

First during training it opens text files from a folder and reads them, splitting words at spaces. For each word, it creates a text file named like that word and into it writes or appends a next word that came after it. After reading and learning from the whole database, you are left with the model folder full of text files. I know I should have used a better data structure for that, but I took the easiest way possible to test the idea at all.

When generating text, it looks at last word that appeared, finds it in the model folder and chooses a random word from the text file names after the word. This way, it chooses the next word to write based on highest probability of what that word should be, as learned from training material.

In other words, it had learned during training what words come after other words and what is the probability of that. And based on that data it choses next word to generate on whatever is most likely to appear after last word that is written. Since it only takes the last word into account, we sadly can't talk about any context understanding in case of this LLM.
