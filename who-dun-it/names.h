#ifndef NAMES_H
#define NAMES_H

#define GRN     "\x1b[32m"
#define RESET   "\x1b[0m"
#define RED     "\x1b[1;31m"
#define MAG     "\x1b[35m"
#define BLU     "\x1b[34m"
#define YEL     "\x1b[4;33m"

#define NOAH "noah|nevens|nowuh|broah"
#define DAGAN "dagan|karp"
#define KELLER "bob|keller"
#define MIARF "marcos is always right foundation|miarf"
#define RAJ "raj|sawhney|short king"
#define KEVIN "kevin|kong|king kong"
#define BUSH "elliot|bush|e|virus"
#define DEVO "devon|overbey|devdev|devo"
#define PACO "me|you|marcos|paco|acosta"
#define LENNY "lenny|fukshansky|leonid"
#define PATRICK "noah's dad|patrick|nevens"
#define DOUG "doug|goodwin"
#define ABEL "abel|soperstein|grutor"
#define DODDS "zach|dodds"
#define ANSHUL "anshul|kamath|angel|anshie"
#define MICHELLE "michelle|lum|milum"
#define EVAN "evan|coulson|coulsussy|sandwhich\\?"
#define BEN_MOUL "ben moul"
#define PYTHON "wiki\\.python\\.org"
#define DEAN_EVETTH "evetth"
#define AVA "ava|fascetti"
#define BRANDON "brandon|bonifacio"
#define ORRISON "o|orrison"
#define VANYA "vanya|bhardwaj"
#define PROF_TALVITIE "erin|talvitie"
#define PROF_DONNELLY "donnelly"
#define HENRY "henry|pick|picko mode"
#define ILTON "mark|ilton"
#define JOSH "josh"
#define DAN "dan|daniela|sechen"
#define RJ "rj|barnes"
#define BANG "lucas|bang"
#define KAYA "kaya|lane"
#define GEORGIA "georgia"
#define KHAYA "khaya|kingston"
#define DAVID "david|pitt"
#define JAMES "james|barrett"
#define FAM "f&m|f & m|facilities & maintenance|f and m|facilities and maintenance"
#define PROF_GEORGE "george"
#define ARJUN "arjun|kamath"
#define LAUREN "lauren|west"
#define BREEDEN "katherine|breeden"
#define STEINBERG "paul|steinberg"
#define JOHNNY "johnny"
#define KUENNING "geoff|kuenning"
#define BURNS "burns"
#define WLOKA "calden|wloka"

typedef struct question_s {
  const char *question;
  const char *solution;
} question_t;

extern const question_t questions[];

void win_message(int score);
void DEFINITELY_NOT_KEYPHRASE();

#endif
