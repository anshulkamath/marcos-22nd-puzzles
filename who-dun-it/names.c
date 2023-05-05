#include "names.h"

#include <stdio.h>
#include "keyphrase.h"

const question_t questions[] = {
  { "Oh no, I'm perpetuating white supremacist capitalism with my quotient rule!", DAGAN },
  { "I don't think your family loves you.", NOAH },
  { "Modernize yourselves!", KELLER },
  { "Presumably everyone here has life goals.", KELLER },
  { BLU"Rafael: \"How do you make your tortillas so big?\"\n"GRN"______:\n"BLU"Rafael:\n"GRN"______: \"Yeast.\""RESET, NOAH },
  { "\"_________\", said in Chinese for an entire year, assumed to mean \"ice in my veins.\"", "graph edge" },
  { "The grutor really had the audacity to give me a 0 when the syllabus says you get one point for attempting the problem.", KEVIN },
  { "It looks like it's going to be much bigger than we would have hoped a month ago.", BUSH },
  { "It's amazing how fast the coronavirus has spread.", BUSH },
  { "\"I told you this day will come, but you have been beaten by your own stupidity,\" in Japanese", DEVO },
  { "It's pretty self explanatory, mainly because I can't explain it.", PACO },
  
  { "Alright, where's the ceiling?", AVA },
  { "Thank you for class!", BRANDON },
  { "And it turns out these subgroups can be embedded in this symmetric group, which begs the question, are there any other groups can be embedded inside of other groups?", ORRISON },
  { "I hate hats on myself but love hats as a concept.", VANYA },
  { "So, uh, basically this is terrible in every possible scenario [sic]... nothing about this is good, you should never do this.\nBut then it gets worse.", PROF_TALVITIE },
  { "Tfw you do all of your homework for the week on Monday but then you realize you have to do all the work for next Monday now.", ANSHUL },
  { "I was trying to walk the line of telling you what you needed to know but not burdening you with the truth.", PROF_TALVITIE },
  { "I promise what is going to be on the midterms is problems.", PROF_DONNELLY },
  { "Yup my mind went right from raccoon sex to Marcos.", HENRY },
  { "Well I\nThe", NOAH },
  { "We are enthusiastic about working with students who may have fabricated data.", ILTON },
  { "Oh you meant a period as in \".\"", NOAH },
  { "Like, why fix something that's already broken?", JOSH },
  { "I got so immersed I stopped paying attention.", ANSHUL },
  { "(aside) I need to learn how to shut the fuck up sometimes.", ANSHUL },
  { "The devil works hard but the e79 graders work harder.", DAN },

  { "I killed two birds.", DEVO },
  { "Sometimes you gotta reward yourself for doing nothing with your life.", DEVO },
  { "Daniela you take a swing at me or anshul and you miss by three hours.", PACO },
  {
    "Normally I say no calculators in my class, but with that being said I have "
    "no idea how you will use a calculator in this class. Therefore, I will instead "
    "say that if you find a way to use a calculator in this class, let me know. "
    "I will be entertained.", LENNY
  },
  { "Eh today's been going alright. I put the kids in breakout rooms for discussion. Then when "
    "I went to check on them, one of the rooms had four black screens and no one was talking.",
    PATRICK
  },
  { "Still having trust issues, sorry.", DOUG },
  { "(aside) How do I blame Anshul for this", PACO },
  { 
    "Every soldier should want to become a general… or so I was told when I was a kid in Russia. "
    "In the same spirit, every commutative ring with identity should want to become a field. "
    "This is kind of the pinnacle of creation, being a field. "
    "Because life is good [when you're a field]. "
    "Think of it as the American dream; if you really want something you can get it. "
    "If a ring really wants to become a field, who is there to stop him? "
    "Well, I can tell you who: zero divisors.", LENNY
  },
  {
    "For those of you that took CS70 over the fall, you'll just be on the other side of the screen. "
    "Well… the same side of the screen, just the other side of the… uh… educational dynamic",
    ABEL
  },
  { "Uncorrelated data is... disconcerting to Homo sapiens.", DODDS },
  { "I was in the middle of deep throating a costco ice cream and I almost died.", ANSHUL },
  { "Being from Pittsburgh, the Pacific Ocean felt, and still feels, fictional.", DODDS },
  { "____ __ _______. (auto-captioned)", "this is awkward" },
  { "If I were Devon, I wouldn't come back to school", MICHELLE },
  { "Okay so remember how I said I was going to work on it?\nI am now at a taco shop.\nI don't know how this happens to me", EVAN },
  {
    "You know, sometimes you live in a dorm and you meet people, and spend enough time with "
    "said people such that you feel that they are, well, somehow important to you. (on friendship)", BEN_MOUL
  },
  { "It doesn't have a very good solution because it's not really a problem", GEORGIA },
  { "If you receive a raw pickle over the network, don't trust it!", PYTHON },
  { "She probably thinks she's safe because she has a good number", KAYA },
  { "Q: \"Will we be able to have 1C parties?\"\n_________: \"I'm down\"", DEAN_EVETTH },

  { "Are- are you Henry?", ANSHUL },
  { "Nah. Shit's superfluous.", DEVO },
  { "Complex analysis is trivial.", RJ },
  { "Wow, that was confusing (coming back from the bathroom).", DEVO },
  { "It's an interesting desktop experience. There's no desktop, that's the experience.", BANG },
  { "She's not crazy, she's just Republican.", KAYA },
  { "If I were an epsilon and got multiplied by two I would just kill myself.", GEORGIA },
  { "It's ok, it happens to the best of us — well, it doesn't, but it happens to you.", KHAYA },
  { "Two best things in the world... stepladders and the Dewey decimal system.", DAVID },
  { "LeBron / James / He's a king / hahaha", JAMES },
  { "Look at these masculine people who speed down the foothill on their mopeds like French countrymen.", BEN_MOUL },
  { "I love Prof Kuenning. He has never once given me advice that put me even remotely on the right track.", EVAN },
  { "I shit you not, I am a morning person.", DEVO },
  { BLU"Rex: Went to Chem23 / forgot my hand-in.\n"GRN"RJ: Brought Van Heuvelen to the _____ ______"RESET, "local hampton" },
  { "If you can't handle this statement, feel free to die.", VANYA },
  { "I'm too emotionally unstable to deal with your chest dent right now.", VANYA },

  { "We have been notified that there is no water on campus.", FAM },
  { "I always feel nervous going to the Scripps pool. But then again, I imagine it's worse for girls going anywhere.", ANSHUL },
  { "This midterm is going to be hard. So hard. I feel sorry for you, honestly.", PROF_GEORGE },
  { "Don't be sad it happened, be glad it's over.", PACO },
  { BLU"Marcos: I'm not the most productive in the morning\n"GRN"Anshul: That's because _______ ____ _______ ___ ___ ___________"RESET, "you're not awake in the morning" },
  { "I suppose they have a right to do engineering, but it's really annoying", KUENNING },
  { "You build a thousand bridges and fuck one goat, and what do they call you? It's not Bridge Builder.", NOAH },
  { "I found a topology where reals are countable. But the intermediate value theorem doesn't hold.", RJ },
  { "If the sock fits, cum in it.", ANSHUL },
  { "I woke up this morning and checked my laptop and there was a directory in my IDE called \"couch website\". No files, no nothing. Just couch website.", EVAN },
  { "I've made a vow to myself to never cum in airplane sinks.", ANSHUL },
  { "We are pregaming breakfast.", ARJUN },
  { "The highest level of Google engineer is the lowest level of trapeze artist.", LAUREN },
  { "Instant cringe moment.", BREEDEN },
  { "Getting two concussions is like, alright. But a kindergartener getting two concussions? That's hilarious.", STEINBERG },
  { "If they let me work on iOS, they'll let you work on anything.", JOHNNY },
  { "*wheelchairs self to board*\n*stands up*", KUENNING },
  { "If everything is a hammer, then everything starts to look like a nail.", BURNS },
  { "In their language, 'shot' means 'pass it to the Brazilian'.", NOAH },
  { "The wise man makes avocado toast at 4am and is still starving for breakfast.", DAN },
  { "Arguably — and when I say arguably, I mean I know I'm right —", NOAH },

  { "I wrote the next Jane Austen novel. You can read it if you'd like. It's unreadable.", DOUG },
  { "She's my STEP-grandma, actually", DEVO },
  { "Are... you memeing right now?", WLOKA },
  { "Wait, we're talking about the same person right? Skeleton with tattoos?", RAJ },
  { "Sometimes you just gotta die on a hill.", RAJ },
  { "I've never met a prof that hasn't pitied me", HARRY },
  { "You will have a long life... and a small head", CLAIRE },
  { BLU"Marcos: Wait, you can't say that\n"GRN"Anshul: ___________ ___ _________?"RESET, "gramatically or racially" },
  { "It's not time, but it's proportional to time", RUTH },
  { "You see, this is why people end up hating C. You can be doing something completely innocuous, like assigning data here and there, and then end up totally committing crimes against humanity", SCOTT },
  0,
};

void win_message(int score) {
  printf(
    "Congratulations on finishing with a score of %d!\n"
    "Now, I might have lied to you about the technical part of this puzzle...\n"
    "You should open this executable in GDB and look at the source code for main().\n",
    score
  );

  DEFINITELY_NOT_KEYPHRASE();
}
