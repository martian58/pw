import subprocess,time,random

list=[
	'''
                                      ▓▓▓▓▓
                               ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓
                            ▓▓▓▓▓▓▚▚▚$$$$$$$▚▚▚▓▓▓▓▓▓
                          ▓▓▓▓▚▚$$$$$$$$$$$$$$$$$▚▚▚▓▓▓
                        $▚▚▚▚$$$$$**!!!;;;!!!**$$$$$▚▚▚▚$
                       $▚▚▚$$$$**!!;::~~~~~~:;!!**$$$▚▚▚▚$
                      $$▚▚$$$$*!;;:~-,     ,-~:;;!*$$$$▚▚▚$
                      $$$$$$**!;:~-,          -~:;!**$$$$$$
                     *$$$$$$**!;:-,           ,-~;!!*$$$$$$*
                     *$$$$$$**!;:-             -::;!*$$$$$$*
                     !*$$$$$$***!;~           ,~:!!**$$$$$$!
                     !**$$$$$$$$**!;         :!!!$*$$$$$$$*!
                     ;!*$$$$$▚▚▚▚▚▚$$*     *$$$▚$▚▚$$$$$$*!;
                      ;!*$$$▚▚▚▚▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▚▚▚▚$$$$*!;
                      ~;!*$$$$▚▚▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▚▚$$$$**;~
                       ~;!**$$$▚▚▚▓▓▓▓▓▓▓▓▓▓▓▓▓▚▚▚$$$**!;~
                        ,:;!*$$$$$▚▚▓▓▓▓▓▓▓▓▓▚▚$$$$$*!;:
                          ,~;!**$$$$$$$$$$$$$$$$$**!;:-
                            ,~:;;!!**$$$$$$$**!!;;:-
                                --::::;;;;;:::~--
                                ''',
	'''
                                ▓▓▓▓▓▓▓▓▓▓▓▓▓
                            ▓▓▓▓▓▓▓▓▓▚▚▚▚▚▚▚▓▓▓▓▓
                          ▓▓▓▓▓▚▚▚$$$$▚*$$$$$$$▚▚▚▓▚
                        ▓▓▓▚▚▚▚$$$$$**********$*$$$▚▚▚
                      ▚▚▚▚▚▚▚$$$***!;;;;;;;;;!!!**$*$$$
                     $▚▚▚▚$$$$**!!;:~~~----~~:::;!!**$$$
                    $$▚▚$$$$**!!;:~-,       ,--::;!!**$$*
                    $$$$$$$**!;;:~-            -~:;!!****
                   *$$$$$$**!!;:~-             ,~:;!!****!
                   **$$$$***!;::~,             -~:;!!****!
                   !********!;;:~-           ~-:;;!!****!;
                   ;!*******!!!;:;:~        ;**$**$$****!;
                   :!!*********!***!!!    $▚▓▓▓▓▚▚▚$$$**;
                    :;!**********$$$$▚▚▓▓▓▓▓▓▓▓▓▓▚▚$$**!:
                     ;;!!!*****$$$$▚▚▓▓▓▓▓▓▓▓▓▓▓▚▚$$$*!:
                      ~;;!!!****$$$▚▚▚▓▓▓▓▓▓▓▓▓▚▚$$$*!~
                       ~:;;!!!*****$$$▚▚▚▚▚▚▚$$$$$*;:,
                         -~:;;!!***$$$$$$$$$$$**!;~,
                           ,-~:;;;!!!!*****!!;:~-
                                ,--~~~~~~~--,
''',
	'''
                                    ▓▓▓▓
                             ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓
                          ▓▓▓▓▓▓▓▓▓▚▚▚▚$$$$$▚▚▚▚▚
                        ▓▓▓▓▓▓▚▚▚▚$$$*$$$$$*****$$$
                      ▚▓▓▓▓▚▚▚$$$$*****!!!!!!!!!****$
                     ▚▚▚▚▚▚▚▚$$*$**!!;;;:::::::;;!!***
                    ▚▚▚▚▚$$$$$**!!;;:~--,,,,,--~::;!!!!
                   $$$$$$$$***!!;;:~--         ,-~:;;!!
                  *$$$$$$$$**!!;:~~,            --~:;!!;
                  *$$$$$$***!!;::~-             -~~:;;!;
                  **$*$****!!;::~-,           ,-~:;;;;;;
                  !*******!!!;;:~-          ;~~:;;;!!!;:
                  !!*****!!!;;::~-,-      :$▚▚▚$$***!!;
                  ;!!!!!!!!!;;;:::~::;  $▓▓▓▓▓▓▓▚▚$**!:
                   ;;!!!!!!!!;;;;;;;!*$▚▓▓▓▓▓▓▓▓▚▚$*!:
                   ~;;;;;!!!;;;;;!!!**$▚▓▓▓▓▓▓▓▚▚**!:
                    -::;;;;;;;;!!!!!**$$▚▚▓▚▚▚$$$*!~
                     ,~:::;;;;;;!!!!****$$$*$*$*!:,
                       ,~~::::;;;;!!!!!!*!**!!;:,
                          ---~~~:::;;;;;;;::~,
                               ,,-------,
                               ''',
	''''
                                ▓▓▓▓▓▓▓▓▓▓▓▓
                            ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▚▚▚▚▚
                         ▓▓▓▓▓▓▓▓▓▓▚▚▚▚▚$$$**$$$$▚
                       ▚▓▓▓▓▓▓▓▚▚▚▚$$$****!!*;;*!**
                      ▚▓▓▓▓▓▚▚▚▚$$$$$***!!!;;;;;;;;!
                     ▚▚▚▚▚▚▚▚$▚$$$$**!;;;:~~~~~~~::;;
                    $▚▚▚▚▚▚$$$$$**!!;;:~~-,,   ,,-~:;
                   $$▚▚▚$$$$$***!!!;:~~-         ,-~::
                  *$$$$$$$$$**!!!;;:~-,           -~::
                  *$$$$$$$***!!;;::~-,           ,-~~~
                  **********!!;;::~-,         ,--~~::~
                  !*******!!!!;;:~-,      !!:::::::::
                  !!***!!!!!!;;::~-,    :▚▓▓▓▚▚*!!;;~
                  ;!!!!!!!!!;;::~~-,  $▚▓▓▓▓▓▓▓▚$*!:
                  :;;!!!!!;;;;::~~~--~;*▚▓▓▓▓▓▓▚**:
                   :;;;;;;;;;::::~~~~:;!$▚▚▚▚▚$*!:
                   -::::::::::::::~:::;!**$$***!:
                    -~~:::::::::::::::;;;!!!!!;-
                      --~~~~~~~~~~~::::;;;;::-
                        ,,-----~~~~~~~~~~~-
                             ,,,,,,,,,,
	''', '''
                                 ▓▓▓▓▓▓▓▓▓▓▓▓▓
                              ▓▓▓▓▓▓▓▓▓▓▓▓▓▚▚▚▚▚▚
                            ▓▓▓▓▓▓▓▓▓▓▓▚▚▚▚$$$****
                          ▓▓▓▓▓▓▓▓▓▓▚▚▚$$$$*!!!!;;!
                        ▚▓▓▓▓▓▓▓▓▚▚▚▚$$$**!!!!;:~:;:
                       ▚▚▚▓▚▚▚▚▚▚▚▚$$$***!!;::~~--~~
                      $▚▚▚▚▚▚▚▚▚$$$$**!*;;:~~-,   ,-
                     $$▚▚▚▚▚▚$$$$$***!!;;:~-,      ,
                    *$$$▚$$$$$$$***!!!;;:~-        ,
                    *$$$$$$$$$****!!;;:~~,        ,,
                   ;**$$$$$$****!!!;;::-, ,    ,,--
                   !***********!!;;:::-, $$;::::~~-
                   !!*******!!!!;;;:~~-, ▓▓▓▚*!!:~
                   ;!!!!!!!!!!;;;:::~-, ▓▓▓▓▓▚*!:,
                   ;;!!!!!!!;;;;::~~--, $▚▓▓▚$!;-
                    ;;;;;;;;;;;::~~~-, ,;*$**!;-
                    ::;;;;;;::::~~~--,,,~;;!;;,
                     ~:::::::::~~~---,,-~:~;~
                      ~~~~~~~~~~-----,--~~~,
                       ,-----------,,,,,,
                           ,,,,,,,,,
	''', '''
                                     ▓▓▓▓▓▓▓▓▓▓▓
                                  ▓▓▓▓▓▓▓▓▓▓▓▓▓▚▚▚
                                ▓▓▓▓▓▓▓▓▓▓▓▓▚▚▚▚$$*
                              ▚▓▓▓▓▓▓▓▓▓▓▓▓▚▚$$$*!!;
                             ▚▓▓▓▓▓▓▓▓▓▓▓▚▚▚$$**!!;:
                           *▚▚▓▓▓▓▓▓▓▚▚▚▚▚$$$**!!::-
                          $▚▚▚▚▚▚▚▚▚▚▚▚$▚$$***!;::,
                          $▚▚▚▚▚▚▚▚▚▚$▚$$$**!!;:~,
                         $$$▚▚▚▚▚▚$$$$$$**!!!;:~,
                        *$$$$▚$$$$$$$$***!!;;:~,
                       !*$$$$$$$$$$$***!!;;;:~-
                       !*$*$$$$$$*****!!!;::~- ,
                       !************!!!;;::~- ~,
                      ;!**********!!!;;;:~~- ;~
                      ;!!!!!!!!!!!!!;;:::~-,;:
                      :;!!!!!!!!!;;;;::~~-,:~
                       ;;;;;;;;;;;::::~--, -
                       ::;;;;;;:::::~~--, -
                       ~~::::::::~~~~-,,
                        -~~~~~~~~~--,,,
                          --------,,,
	''', '''
                                           ▓▓▓▓▓▓
                                       ▚▓▓▓▓▓▓▓▓▓▓▓▚
                                     $▓▓▓▓▓▓▓▓▓▓▓▓▓▚$
                                    ▚▚▓▓▓▓▓▓▓▓▓▓▓▓▚▚$*
                                   $▚▓▓▓▓▓▓▓▓▓▓▓▚▚▚$$*;
                                 !$▚▚▓▓▓▓▓▓▓▓▓▚▚▚▚▚$*!:
                                !$▚▚▚▓▓▓▓▓▓▓▚▚▚▚▚$$$*!:
                               !$$▚▚▚▚▚▚▚▚▚▚▚▚▚$$$**!;
                               *$▚▚▚▚▚▚▚▚▚▚▚▚▚▚$***!;:
                              *$$$▚▚▚▚▚▚▚▚$$$$$$**!;:~
                             **$$$$▚▚$$$$$$$$***!!;;~
                            ;**$$$$$$$$$$$$****!!;:~,
                            !***$$$$$$$$$*****!;;;:-
                           ;!****$$$********!!!;::-
                           ;!!***********!!!!;;::-
                           ;!!!**!****!!!!;;;::~-
                          :;!!!!!!!!!!!!;;;:::~-
                          :;;;;!!!!;!;;;;:::~-,
                          ~::;;;;;;;;;:::~~~-,
                           ~:::::::::::~~--,
                            -~~~~~~~~~~--,
	''', '''
                                           ▓▓▓▓▓▓▓▓▓▓
                                         $▚▓▓▓▓▓▓▓▓▓▓▓▓
                                        *$▚▓▓▓▓▓▓▓▓▓▓▓▓▚$
                                      ;;*▚▚▓▓▓▓▓▓▓▓▓▓▓▓▚▚*
                                     ;-!$▚▚▓▓▓▓▓▓▓▓▓▓▓▚▚$$
                                     ~!*$▚▚▓▓▓▓▓▓▓▓▓▓▚▚▚$*
                                    :~*$$▚▚▚▓▓▓▓▓▓▓▓▚▚▚$$*;
                                   !:*$$▚▚▚▚▚▚▓▓▚▚▚▚▚▚$$**;
                                  **!*$$▚▚▚▚▚▚▚▚▚▚▚▚▚$$$*!:
                                 *▚!**$$$▚▚▚▚▚▚▚▚▚▚▚$$**!;
                                 ▚:**$$$$▚▚▚▚▚▚$▚$$$$$*!;;
                                ▚▓!**$$$$$$$▚$$$$$*****!;-
                               $▚!!**$$$$$$$$$$$*$**!!!;~
                              !$;!****$*$$$$$$$****!!;;~
                              !;!!***************!!;;;~
                             ;;;!!!**********!!!!!;;:~,
                             :;;;!!!!!!!!!!!!!!;;;::~
                             ::;;;!!!!!!!!!!;;;:::~-
                             ~::;;;;;;;;;;;;:::~--,
                              ~~::::::::::::~~--,
	''', '''
                                               ▓▓▓
                                         ▚▚▚▚▓▓▓▓▓▓▓▓▓▓
                                       $***$▚▚▚▓▓▓▓▓▓▓▓▓▓▓
                                     *!::;!**$▚▓▓▓▓▓▓▓▓▓▓▓▓
                                    !;;~~~;!*$▚▚▓▓▓▓▓▓▓▓▓▓▓▚
                                  *!;:-,,-:!*$▚▚▚▓▓▓▓▓▓▓▓▓▓▚$
                                 *!;:-   ,:!*$▚▚▚▓▓▓▓▓▓▓▓▓▚▚$
                                **!;~-   -;*$$▚▚▚▚▓▓▓▓▓▓▚▚▚$$!
                               !$$*!:-   ;!*$$▚▚▚▚▚▚▚▓▚▚▚▚▚$*!
                               $▚▓▚*!;~-~!**$$▚▚▚▚▚▚▚▚▚▚▚▚$$*!
                              *▓▓▓▓▓▓$!~;**$$$▚▚▚▚▚▚▚▚▚$$$$*!;
                              ▚▓▓▓▓▓▓▓*!!*$$$$$▚▚▚▚▚▚▚$$$$**!:
                             !▚▓▓▓▓▓▓;!!**$$$$$$▚▚$$$$$$**!!;
                             *▚▓▓▚$!!!****$$$$$$$$$$$$$***!;~
                             *$$$**!******$$$$$$$$$$****!!;:
                             !***************$********!!;;~
                             :!!!!!!!**************!!!;;:~
                             ~;;!!!!!!!*!*!!*!!!!!!;;;::-
                              ~:;;!!!!!!!!!!!;!;;;;;:~-
                               ~~::;;;;;;;;;;;;:::~~-
	''', '''
                                         ▓▓▓▓▓▓▓▓▓▓▓▓▓
                                     ▚▚$$$$▚▚▚▚▓▓▓▓▓▓▓▓▓▓
                                   $$*!!!!!***▚▚▚▓▓▓▓▓▓▓▓▓▓
                                 $*!!!!:;;:;;!*$$▚▓▓▓▓▓▓▓▓▓▓$
                                $*!!;:~~-~~::!!*$$▚▓▓▓▓▓▓▓▓▓▚$
                              !$**!;~-,    -~;!*$$▚▚▓▓▓▓▓▓▓▓▚▚
                              $$**;:~,      -;!**$▚▚▓▓▓▓▓▓▓▓▚▚*
                             $▚▚**;:~,      -;!*$$▚▚▚▚▓▓▓▓▚▚▚▚*
                            *▚▚▓▚▚$!:-      :;**$$$▚▚▚▚▚▚▚▚▚$$*
                            $▚▓▓▓▓▓▚*:,    ~;!*$$$▚▚▚▚▚▚▚▚▚▚$$*
                           :▚▓▓▓▓▓▓▓▚*,   :!!*$$$$▚▚▚▚▚▚▚▚▚$$**
                           ;▚▓▓▓▓▓▓▓▓▚*  ;!**$$$$$$$▚$$$$$$$*!!
                           ;$▓▓▓▓▓▓▓▚$******$$$$$$$$$$$$$***!!:
                           :*▚▚▓▓▓▓▚▚$$$$$$$$$$$$$$$$$$$$**!!:
                            ;*$▚▚▚▚▚▚$$$$$$$$$$$$$$$$*****!;:
                            ~!!$$$$$$$$$$*$$**$*********!;;:
                             :;;!**$***************!!!!;;:~
                              ~;!;!!!!******!*!!!!!!;;::~
                                ~:;;;;!!!!;!;;;;;;:::~-
                                ''', '''
                                      ▓▓▓▓▓▓▓▓▓▓▓▓▓▓
                                   ▓▓▚▚▚▚▚▚▚▚▓▓▓▓▓▓▓▓▓▓
                                ▚▚▚$$**$*!**$$$▚▚▚▓▓▓▓▓▓▓▓
                              ▚▚$$****!!!!!!!!*$$▚▚▚▓▓▓▓▓▓▓$
                             $$$$**!;::~~~~:;!!**$$▚▚▓▓▓▓▓▓▓▚
                            $$$$*!;:~-,   ,-~:;;**$▚▚▚▚▓▓▓▓▓▚$
                           $$$$*!;:~-       ,-~;!**$▚▚▚▚▓▓▓▚▚▚
                          *$▚▚$**;:-,        ,~;!**$▚▚▚▚▚▚▚▚▚$*
                          $▚▚▚▚▚$*;~,         ~;!*$$$▚▚▚▚▚▚▚▚$*
                         !$▚▓▓▓▓▚▚$!-        -;!**$$$▚▚▚▚▚▚▚$$*
                         ;$▚▓▓▓▓▓▓▚$*        ;!**$$$$▚▚▚▚▚$$$**
                         ;$▚▓▓▓▓▓▓▓▓▓$     !****$$$$▚▚▚$$$$$$*!
                         :*$▚▓▓▓▓▓▓▓▓▓▚▚$$$$$$$$$$$$$▚$$$$$**!:
                          ;*$▚▓▓▓▓▓▓▓▓▓▓▚▚▚▚▚▚$$$$$$$$$$$***!;
                          ~!*$▚▓▓▓▓▓▓▓▓▓▚▚▚▚▚▚$$$$$$$$****!!:
                           :!!*$▚▚▚▚▚▚▚▚▚▚▚▚$$$$$$$$****!!;:
                            ~;!!*$$$$$$$$$$$$*$$*****!!!;:~
                              :;!*****$**$$******!!!;;::~
                                -:;;;!!!!!!!!!!;;;;:~-,
''', '''
                                   ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓
                                ▓▓▓▚▚▚▚▚▚▚▚▚▚▓▓▓▓▓▓▓▓▓
                             ▓▓▚▚▚$$$$$$**$$$$$▚▚▓▓▓▓▓▓▓
                           ▚▚▚▚$$$$***!!!!!!**$$$$▚▚▚▓▓▓▓▓
                          ▚▚▚$$$*!!!;::::::::;!**$$$▚▚▚▓▓▓▚
                         $▚▚$$**!!;~--,,  ,,-~:;!**$$▚▚▚▚▚▚▚
                        *$▚$$$*!;:~-,        ,~:;!*$$$▚▚▚▚▚▚$
                        $$▚$$$*!;~-           ,~:!!*$$▚▚▚▚▚▚$*
                       *$$▚▚▚$$*!:-           ,~;!**$$$▚▚▚▚$$*
                       !$$▚▚▚▚▚$**;~          ~:!!*$$$$▚▚▚$$$!
                       !*$▚▚▚▚▚▚▚▚$!         ~;!**$$$$$$$$$$$!
                       ;*$▚▚▚▓▓▓▓▓▓▓▚$      **$$$$$$▚▚$$$$$**;
                        !*$▚▚▓▓▓▓▓▓▓▓▓▓▓▓▚▚▚▚▚▚▚▚▚▚▚▚$$$$$*!!
                        ;!$$▚▚▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▚▚▚▚▚▚$$$$$**!:
                         :!*$$▚▚▓▓▓▓▓▓▓▓▓▓▓▓▓▓▚▚▚▚$$$$$**!;:
                          :;*$$$▚▚▚▓▓▓▓▓▓▓▚▚▚▚▚$$$$$$**!!;~
                           ,;!*$$$$$$$▚▚▚▚$$$$$$$$***!;:~
                             ,:;!!!*$$$$$$$$*****!!;;:~
                                -~::;!!!!!!!!!;;;:~-,
    ''',
]

color_list=["\033[1;31m","\033[1;32m","\033[1;33m","\033[1;37m","\033[1;35m","\033[1;34m"]

while True:
    rnd_color=random.choice(color_list)
    for i in list:
        print(f"{rnd_color}{i}")
        print("\n")
        print("Press 'Ctrl+C' to quit.")
        time.sleep(0.1)
        subprocess.run("clear")
