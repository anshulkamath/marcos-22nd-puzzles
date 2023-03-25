#ifndef NAMES_H
#define NAMES_H

#define PROF(x) x"|prof "x"prof\\. "x

#define NOAH "noah|nevens|noah nevens|nowuh|broah"
#define DAGAN "dagan|karp|dagan karp"
#define KELLER "bob|keller|bob keller|prof keller|prof\\. keller"
#define MIARF "marcos is always right foundation|miarf"
#define RAJ "raj|raj sawhney|short king"
#define KEVIN "kevin|kevin kong|king kong|kong"
#define BUSH "prof\\. bush|bush|elliot|elliot bush|the virus|the coronavirus|prof e\\. bush|prof\\. e\\. bush|e\\. bush"
#define DEVO "devon|devon overbey|devdev|devo"
#define PACO "me|you|marcos|paco"
#define LENNY "lenny|prof\\. fukshansky|leonid"
#define PATRICK "patrick|patrick nevens|mr\\. noah's dad|mr\\. nevens"
#define DOUG "doug|prof\\. goodwin|doug goodwin|prof goodwin"
#define ABEL "abel|head grutor|grutor guy|grutor dude|abel soperstein"
#define ANSHUL "anshul|anshul kamath|angel|anshie"
#define MICHELLE "michelle|michelle lum|milum"
#define EVAN "evan|evan coulson|coulsussy|sandwhich\\?"
#define BEN_MOUL "ben moul"
#define PYTHON "wiki\\.python\\.org"
#define DEAN_EVETTH "dean evetth|evetth"
#define AVA "ava|ava fascetti"
#define BRANDON "brandon|brandon bonifacio"
#define ORRISON "orrison|prof\\. o|prof\\. orrison|prof o|prof orrison"
#define VANYA "vanya|vanya bhardwaj"
#define PROF_TALVITIE "erin|prof\\. talvitie|erin talvitie|prof talvitie"
#define PROF_DONNELLY PROF("donnelly")
#define HENRY "henry|henry pick|picko mode"
#define ILTON PROF("ilton")"mark|mark ilton"
#define JOSH "josh"
#define DAN "dan|daniela|daniela sechen|dan down"
#define RJ "rj|rj barnes"
#define BANG PROF("bang")
#define KAYA "kaya|kaya lane"
#define GEORGIA "georgia"
#define KHAYA "khaya|khaya kingston"
#define DAVID "david|david pitt"
#define JAMES "james|james barrett"
#define FAM "f&m|f & m|facilities & maintenance|f and m|facilities and maintenance"
#define PROF_GEORGE PROF("george")
#define ARJUN "arjun|arjun kamath"
#define LAUREN "lauren|lauren west"
#define BREEDEN PROF("breeden")
#define STEINBERG PROF("steinberg")
#define JOHNNY "johnny"
#define KUENNING PROF("kuenning")
#define BURNS PROF("burns")
#define WLOKA PROF("wloka")"calden"

typedef struct question_s {
  const char *question;
  const char *solution;
} question_t;

extern const question_t questions[];

void win_message(int score);
void DEFINITELY_NOT_KEYPHRASE();

#endif
