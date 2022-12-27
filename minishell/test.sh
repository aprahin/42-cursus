#!/bin/bash
# MINISHELL-TESTER

RESET="\033[0m"
BLACK="\033[30m"
RED="\033[31m"
GREEN="\033[32m"
YELLOW="\033[33m"
BLUE="\033[34m"
MAGENTA="\033[35m"
CYAN="\033[36m"
WHITE="\033[37m"

DIM="\e[2m"

BOLDBLACK="\033[1m\033[30m"
BOLDRED="\033[1m\033[31m"
BOLDGREEN="\033[1m\033[32m"
BOLDYELLOW="\033[1m\033[33m"
BOLDBLUE="\033[1m\033[34m"
BOLDMAGENTA="\033[1m\033[35m"
BOLDCYAN="\033[1m\033[36m"
BOLDWHITE="\033[1m\033[37m"

PAUSE=0.5

# Compile and set executable rights
#make -C ../ > /dev/null
#cp ../minishell .
exec 2>/dev/null
chmod 755 minishell
rm -rf tmp
mkdir tmp
cd tmp

while getopts s:vV flag
do
	case "${flag}" in
		s) SPEED=${OPTARG};;
		v) VERBOSE="yes";;
		V) VERBOSE="YES";;
	esac
done

function exec_test()
{
	TEST1=$(echo "((" $@ " || echo \$?) || true) && exit" | ../minishell 2>/dev/null)
	ENV1=$(echo -e "\nLS: " && ls -la && echo "CAT: " && cat *)
	ES_1=$?
	TEST2=$(echo "((" $@ " || echo \$?) || true) && exit" | bash 2>/dev/null)
	ENV2=$(echo -e "\nLS: " && ls -la && echo "CAT: " && cat *)
	ES_2=$?
#	TEST1=$(echo "((" $@ " || echo \$?) || true) && exit" | ../minishell 2>/dev/null)
#	ENV1=$(echo -e "\nLS: " && ls -la && echo "CAT: " && cat *)
#	ES_1=$?
	if [ "$TEST1" == "$TEST2" ] && [ "$ES_1" == "$ES_2" ] && [ "$ENV1" == "$ENV2" ]; then
	#	printf " $BOLDGREEN%s$RESET" "✓ "
		printf " $BOLDGREEN[OK]$RESET "
	else
	#	printf " $BOLDRED%s$RESET" "✗ "
		printf " $BOLDRED[KO]$RESET "
	fi
	printf "$CYAN \"$@\" $RESET"
	FULL=$(echo "$TEST1")
	PREVIEW=$(echo "$TEST1" | head -5)
	if [[ $VERBOSE == "YES" ]]; then
		printf "\n$DIM$FULL$RESET"
	elif [[ $VERBOSE == "yes" ]]; then
		printf "\n$DIM$PREVIEW$RESET"
	fi
	if [ "$TEST1" != "$TEST2" ]; then
		echo
		echo
		printf $BOLDRED"Your output : \n%.20s\n$BOLDRED$TEST1\n%.20s$RESET\n" "-----------------------------------------" "-----------------------------------------"
		printf $BOLDGREEN"Expected output : \n%.20s\n$BOLDGREEN$TEST2\n%.20s$RESET\n" "-----------------------------------------" "-----------------------------------------"
	fi
	if [ "$ES_1" != "$ES_2" ]; then
		echo
		echo
		printf $BOLDRED"Your exit status : $BOLDRED$ES_1$RESET\n"
		printf $BOLDGREEN"Expected exit status : $BOLDGREEN$ES_2$RESET\n"
	fi
	if [ "$ENV1" != "$ENV2" ]; then
		echo
		echo
		printf $BOLDRED"Your directory : $BOLDRED$ENV1$RESET\n"
		printf $BOLDGREEN"Expected directory : $BOLDGREEN$ENV2$RESET\n"
	fi
	echo
	if [ -z $SPEED ]; then
		sleep 0.025
	else
		sleep $SPEED
	fi
}

printf $BOLDRED"   *     (        )  (        )       (     (     \n"
printf " (       )\ )  ( /(  )\ )  ( /(       )\ )  )\ )  \n"
printf " )\))(  (()/(  )\())(()/(  )\()) (   (()/( (()/(  \n"
printf "((_)()\  /(_))((_)\  /(_))((_)\  )\   /(_)) /(_)) \n"
printf "(_()((_)(_))   _((_)(_))   _((_)((_) (_))  (_))   \n"
printf $BOLDWHITE"|  \/  ||_ _| | \| ||_ _| | || || __|| |   | |    \n"
printf "| |\/| | | |  | .  | | |  | __ || _| | |__ | |__  \n"
printf "|_|  |_||___| |_|\_||___| |_||_||___||____||____| \n"$RESET
echo
sleep 1

# EVALUATION CHART

# SIMPLE COMMAND WITHOUT ARGUMENTS
printf $BOLDYELLOW"SIMPLE COMMAND WITHOUT ARGUMENTS\n"$RESET
sleep $PAUSE
exec_test '/bin/ls'
exec_test '/bin/lsblk'
exec_test '/bin/whoami'
exec_test '/bin/who'
exec_test '/bin/w'
exec_test '/bin/hostname'
exec_test '/bin/dir'
exec_test '/bin/uname'
exec_test '/bin/arch'
exec_test '/bin/true'
exec_test '/bin/false'
exec_test '/bin/du'
exec_test '/bin/df'
exec_test ''
exec_test ' '
exec_test '           '
exec_test '			'

# SIMPLE COMMAND WITH ARGUMENTS
printf $BOLDYELLOW"\nSIMPLE COMMAND WITH ARGUMENTS\n"$RESET
sleep $PAUSE
exec_test '/bin/ls -a'
exec_test '/bin/ls -l'
exec_test '/bin/ls -la'
exec_test '/bin/ls --full-time'
exec_test '/bin/ls -l --author'
exec_test '/bin/ls -bANaNa'
exec_test '/bin/uname -a'
exec_test '/bin/uname -a -m -p'
exec_test '/bin/uname --hardware-platform'
exec_test '/bin/seq 1'
exec_test '/bin/seq 5'
exec_test '/bin/seq 100'
exec_test '/bin/seq 1 10'
exec_test '/bin/seq -50 50'
exec_test '/bin/seq 0 5 100'
exec_test '/bin/seq -0.42 0.5 42'
exec_test '/bin/seq -s -42 42'
exec_test '/bin/seq -s- -20 20'
exec_test '/bin/seq --separator=SEPARATOR -3 0.1 3'
exec_test '/bin/touch ./tmpfile'
exec_test '/bin/chmod 777 tmpfile'
exec_test '/bin/cat tmpfile'
exec_test '/bin/cp tmpfile ./tmpfile2'
exec_test '/bin/rm -rf tmpfile'
exec_test '/bin/rm -rf tmpfile2'
exec_test '/bin/touch infile'
exec_test '/bin/touch midfile'
exec_test '/bin/touch outfile'
exec_test '/bin/chmod 000 midfile'

# ECHO TESTS
printf $BOLDYELLOW"\nECHO\n"$RESET
sleep $PAUSE
exec_test 'echo test'
exec_test 'echo test      lol'
exec_test 'echo -n lol mdr'
exec_test 'echo -n -n -n xd xd'
exec_test 'echo'
exec_test 'echo '
exec_test 'echo            '
exec_test 'echo			'
exec_test 'echo -n 42 -n'
exec_test 'echo 42 -n -n -n -n hello'
exec_test 'echo hello world'
exec_test 'echo -N'
exec_test 'echo -abcdefg hijklmnop'
exec_test 'echo -------n'
exec_test 'echo n-n owo'
exec_test 'echo hello world foo bar HELLO WORLD food bar'
exec_test '                echo hello                     '
exec_test 'echo echo echo echo echo echo echo'

# EXIT
printf $BOLDYELLOW"\nEXIT\n"$RESET
sleep $PAUSE
exec_test "exit"
exec_test "exit 42"
exec_test "               exit"
# BULLSHIT ALERT
# for some reasons, exiting with too many arguments DOESN'T exit and sets
# $? to 1. However, in a subshell, it seems that any commands executed
# after exit with too many arguments AREN'T executed. Is it exiting in the
# subshell? But not in the main shell? How does that make any sense?
# RECTIFICATION: exit with too many arguments fails to quit AND fails to execute anything after for some reasons
#exec_test "exit 42 53 68"
exec_test "exit 259"
exec_test "exit 9223372036854775807"
exec_test "exit -9223372036854775808"
exec_test "exit 9223372036854775808"
exec_test "exit -9223372036854775810"
exec_test "exit -4"
exec_test "exit wrong"
exec_test "exit wrong_command"
exec_test "exit amogus 2738472"
# BULLSHIT ALERT
#exec_test 'exit 7238497 amogus'
exec_test 'exit 23723471284723984789274187892734'
exec_test 'exit 000001'
exec_test 'exit 674837298471097492381749827904707127'
exec_test 'exit 7213487imnotanumber71382947'
exec_test 'exit -0'
exec_test 'exit -------'
exec_test 'exit 423879'
exec_test 'exit 255'
exec_test 'exit 128'
exec_test 'exit 0'
exec_test 'exit 1'
exec_test 'exit -1'
exec_test 'exit ZERO'
exec_test 'exit exit exit'
exec_test 'exit for real now'

# RETURN VALUES
printf $BOLDYELLOW"\nRETURN VALUE\n"$RESET
sleep $PAUSE
exec_test '/bin/ls -a && echo $?'
exec_test '/bin/ls -l && echo $?'
exec_test '/bin/ls -la && echo $?'
exec_test '/bin/ls --full-time && echo $?'
exec_test '/bin/ls -l --author && echo $?'
exec_test '/bin/ls -bANaNa && echo $?'
exec_test '/bin/uname -a && echo $?'
exec_test '/bin/uname -a -m -p && echo $?'
exec_test '/bin/uname --hardware-platform && echo $?'
exec_test '/bin/seq 1 && echo $?'
exec_test '/bin/seq 5 && echo $?'
exec_test '/bin/seq 100 && echo $?'
exec_test '/bin/seq 1 10 && echo $?'
exec_test '/bin/seq -50 50 && echo $?'
exec_test '/bin/seq -0.42 0.5 42 && echo $?'
exec_test '/bin/seq -s -42 42 && echo $?'
exec_test '/bin/seq -s- -20 20 && echo $?'
exec_test '/bin/seq --separator=SEPARATOR -3 0.1 3 && echo $?'
exec_test '/bin/touch ./tmpfile && echo $?'
exec_test '/bin/chmod 777 tmpfile && echo $?'
exec_test '/bin/cat tmpfile && echo $?'
exec_test '/bin/cp tmpfile ./tmpfile2 && echo $?'
exec_test '/bin/rm -rf tmpfile && echo $?'
exec_test '/bin/rm -rf tmpfile2 && echo $?'
exec_test '/bin/ls IDONTEXIST || echo $?'
exec_test '/bin/cat MENEITHERISHOULDNTEXIST || echo $?'
exec_test '/bin/rm WHATSHOULDIREMOVE || echo $?'
exec_test '/bin/seq SEQUENCEOFWHAT || echo $?'
exec_test '/bin/ls THIS IS NOT OKAY || echo $?'
exec_test '/bin/cat WHAT DID YOU SAY || echo $?'
exec_test '/bin/expr || echo $?'
exec_test 'echo $?'
exec_test '/bin/expr $? + $?'
exec_test '/bin/expr $? + $? && /bin/expr $? + $? && /bin/expr $? + $?'
exec_test '/bin/cat midfile || echo $?'
exec_test '/bin/cat infile && echo $?'
exec_test '/bin/cat outfile && echo $?'
exec_test 'ec oh'
exec_test 'a'
exec_test 'c'
exec_test 'e'
exec_test 'ec ho'
exec_test 'c d'
exec_test 'jsafiojefojaeoifjoijweoij'
exec_test '   ec    ho'

# DOUBLE QUOTES
printf $BOLDYELLOW"\nDOUBLE QUOTES\n"$RESET
sleep $PAUSE
exec_test 'echo "cat lol.c | cat > lol.c"'
exec_test 'echo "??????????"'
exec_test 'echo "HELLO 7\}\{4*71}741}/{/~}4277}/27\ WORLD"'
exec_test 'echo "2731 2372    327418723 72 				374"'
exec_test 'echo ";-+={)(}{*||&><__"'
exec_test 'echo "(╯°□°）╯︵ ┻━┻"'
exec_test 'echo "̿̿ ̿̿ ̿̿ ̿'̿'\̵͇̿̿\з= ( ▀ ͜͞ʖ▀) =ε/̵͇̿̿/’̿’̿ ̿ ̿̿ ̿̿ ̿̿"'
exec_test '/bin/seq "1" "5"'
exec_test '/bin/seq -s"SUS" -42 "42"'
exec_test '/bin/expr "2 + 2" - "4 + 4"'
exec_test '/bin/expr "2" + "2" - "4" + "4"'
exec_test '/bin/expr 42 "-" 42'
exec_test '/bin/expr "1984"'
exec_test "echo '$USER'"
exec_test "echo $USER '$PATH'"
exec_test "echo '$USER $PATH $PWD'"
exec_test "echo -n '$USER $PATH HELLO $PWD $SHELL'"
exec_test "echo '$HELP' $SHEESH"
exec_test 'echo "" "" "   "'
exec_test 'echo "             "'
exec_test 'echo "		"'
exec_test 'echo """"""'
exec_test '/bin/seq "" "" ""'
exec_test '/bin/expr " " "    "'
exec_test '/bin/cat "infile"'
exec_test '/bin/cat "midfile'
exec_test '/bin/cat "outfile"'
exec_test '""'

# SINGLE QUOTES
printf $BOLDYELLOW"\nSINGLE QUOTES\n"$RESET
sleep $PAUSE
exec_test "echo 'cat lol.c | cat > lol.c'"
exec_test "echo '??????????'"
exec_test "echo 'HELLO 7\}\{4*71}741}/{/~}4277}/27\ WORLD'"
exec_test "echo '2731 2372    327418723 72 				374'"
exec_test "echo ';-+={)(}{*||&><__'"
exec_test "echo '(╯°□°）╯︵ ┻━┻'"
exec_test "echo '̿̿ ̿̿ ̿̿ ̿'̿'\̵͇̿̿\з= ( ▀ ͜͞ʖ▀) =ε/̵͇̿̿/’̿’̿ ̿ ̿̿ ̿̿ ̿̿'"
exec_test "/bin/seq '1' '5'"
exec_test "/bin/seq -s'SUS' -42 '42'"
exec_test "/bin/expr '2 + 2' - '4 + 4'"
exec_test "/bin/expr '2' + '2' - '4' + '4'"
exec_test "/bin/expr 42 '-' 42"
exec_test "/bin/expr '1984'"
exec_test 'echo "$USER"'
exec_test 'echo $USER "$PATH"'
exec_test 'echo "$USER $PATH $PWD"'
exec_test 'echo -n "$USER $PATH HELLO $PWD $SHELL"'
exec_test 'echo "$HELP" $SHEESH'
exec_test "echo '' '' '   '"
exec_test "echo '             '"
exec_test "echo '		'"
exec_test "echo ''''''"
exec_test "/bin/seq '' '' ''"
exec_test "/bin/expr ' ' '    '"
exec_test '/bin/cat "infile"'
exec_test '/bin/cat "midfile'
exec_test '/bin/cat "outfile"'
exec_test ''''

# ENV
printf $BOLDYELLOW"\nENV\n"$RESET
sleep $PAUSE
exec_test "env | sort | grep -v SHLVL | grep -v _= | grep -v BASH_FUNC"

# EXPORT
printf $BOLDYELLOW"\nEXPORT\n"$RESET
sleep $PAUSE
ENV_SHOW="env | sort | grep -v SHLVL | grep -v _= | grep -v BASH_FUNC"
EXPORT_SHOW="export | sort | grep -v SHLVL | grep -v _= | grep -v OLDPWD"
exec_test 'export ='
exec_test 'export 1TEST= &&' $ENV_SHOW
exec_test 'export ""="" && ' $ENV_SHOW
exec_test 'export TES=T="" &&' $ENV_SHOW
exec_test 'export TE+S=T="" &&' $ENV_SHOW
exec_test 'export TEST=LOL && echo $TEST &&' $ENV_SHOW
exec_test 'export TEST=LOL && echo $TEST$TEST$TEST=lol$TEST &&' $ENV_SHOW
exec_test 'export amogus=sus &&' $ENV_SHOW
exec_test 'export lolxd &&' $ENV_SHOW
exec_test 'export IHAVEXPORT &&' $ENV_SHOW
exec_test 'export IHAVEXPORT=42 &&' $ENV_SHOW
exec_test 'export IHAVEXPORT=10 &&' $ENV_SHOW
exec_test 'export 12374NOTVALID=404 &&' $ENV_SHOW
exec_test 'export ____MAYBE &&' $ENV_SHOW
exec_test 'export ====== &&' $ENV_SHOW
exec_test 'export HEHE32=32 &&' $ENV_SHOW
exec_test 'export 42=42 &&' $ENV_SHOW
exec_test 'export \\\\=\\\\ &&' $ENV_SHOW
# env has this weird BASH_FUNC variable only in minishell 
#exec_test 'export | grep -v BASH_FUNC'
exec_test 'export 30sheesh=DAMN &&' $ENV_SHOW
exec_test 'export VAR MOREVAR ANOTHERVAR=30 && export VAR=20 MOREVAR=$ANOTHERVAR &&' $ENV_SHOW
exec_test 'export HOWMANY=VAR CAN=WE GET=399 && export CAN=$CAN$CAN &&' $ENV_SHOW
exec_test 'export ONE MORE VAR=30 && export VAR=$ONE$MORE &&' $ENV_SHOW
exec_test 'export AAAAA=50 AAAAA=20 AAAAA=10 AAAAA &&' $ENV_SHOW
exec_test 'export A="" B=42 C=$A D=$B$C A=A A= &&' $ENV_SHOW
exec_test 'export ALPHA=ONE 12374=NOTVALID BETA=TWO &&' $ENV_SHOW
exec_test '               export A=B &&' $ENV_SHOW
exec_test 'export sheesh= &&' $ENV_SHOW
exec_test 'export sheesh && export sheesh= &&' $ENV_SHOW
exec_test 'export sheesh=42 && export sheesh+=42 &&' $ENV_SHOW
exec_test 'export sheesh+=hello && export sheesh+=world &&' $ENV_SHOW
exec_test 'export hello=world && export hello &&' $ENV_SHOW
exec_test 'export world=hello && export world= &&' $ENV_SHOW
exec_test 'export amogus+="hello " && export amogus+="i am" && export amogus+=" the imposter" &&' $ENV_SHOW
exec_test 'export A=A && export A+=A && export A+=A && export A+=A && export A+=A && export A+=A && export A+=A && export A+=A && export A+=A && export A+=A && export A+=A && export A+=A && export A+=A && export A+=A && export A+=A && export A+=A && export A+=A && export A+=A && export A+=A && export A+=A && export A+=A && export A+=A && export A+=A && export A+=A && export A+=A && export A+=A && export A+=A && export A+=A && export A+=A && export A+=A && echo $A &&' $ENV_SHOW
exec_test 'export SUS=SUS && export SUS+=$SUS && export SUS+=$SUS && export SUS+=$SUS && export SUS+=$SUS && export SUS+=$SUS && export SUS+=$SUS && export SUS+=$SUS && export SUS+=$SUS && export SUS+=$SUS && export SUS+=$SUS && export SUS+=$SUS && export SUS+=$SUS && export SUS+=$SUS && export SUS+=$SUS && echo $SUS'
exec_test 'export a+=b a+=c a+=d &&' $ENV_SHOW
exec_test 'export HI=HI HI+=$HI HI+=$HI HI+=$HI HI+=$HI HI+=$HI HI+=$HI HI+=$HI HI+=$HI HI+=$HI HI+=$HI HI+=$HI HI+=$HI HI+=$HI HI+=$HI HI+=$HI HI+=$HI HI+=$HI HI+=$HI HI+=$HI HI+=$HI HI+=$HI && echo $HI' 
exec_test 'export stuff= && export stuff &&' $ENV_SHOW
exec_test 'export stuff= && export stuff= stuff= stuff= && export hello=$stuff &&' $ENV_SHOW
exec_test 'export HI=$HI && export HELLO+=$HI && export HI+=$HELLO && export HELLO+=$HI &&' $ENV_SHOW

# UNSET
printf $BOLDYELLOW"\nUNSET\n"$RESET
sleep $PAUSE
exec_test 'unset ='
exec_test 'unset 1TEST &&' $ENV_SHOW
exec_test 'unset ""="" && ' $ENV_SHOW
exec_test 'unset TES=T &&' $ENV_SHOW
exec_test 'unset TE+S=T &&' $ENV_SHOW
exec_test 'unset TEST && echo $TEST &&' $ENV_SHOW
exec_test 'unset TEST && echo $TEST$TEST$TEST &&' $ENV_SHOW
exec_test 'unset amogus &&' $ENV_SHOW
exec_test 'unset lolxd &&' $ENV_SHOW
exec_test 'unset IHAVEXPORT &&' $ENV_SHOW
exec_test 'unset IHAVEXPORT &&' $ENV_SHOW
exec_test 'unset IHAVEXPORT &&' $ENV_SHOW
exec_test 'unset 12374NOTVALID &&' $ENV_SHOW
exec_test 'unset ____MAYBE &&' $ENV_SHOW
exec_test 'unset ====== &&' $ENV_SHOW
exec_test 'unset HEHE32 &&' $ENV_SHOW
exec_test 'unset 42 &&' $ENV_SHOW
exec_test 'unset \\\\=\\\\ &&' $ENV_SHOW
exec_test '             unset &&' $ENV_SHOW
exec_test 'unset &&' $ENV_SHOW
exec_test 'unset 30sheesh &&' $ENV_SHOW
exec_test 'unset VAR MOREVAR ANOTHERVAR && unset VAR MOREVAR &&' $ENV_SHOW
exec_test 'unset HOWMANY CAN GET && unset CAN &&' $ENV_SHOW
exec_test 'unset ONE MORE VAR=30 && unset VAR &&' $ENV_SHOW
exec_test 'unset AAAAA AAAAA=20 AAAAA AAAAA &&' $ENV_SHOW
exec_test 'unset A B=42 C=$A D A=A A= &&' $ENV_SHOW
exec_test 'unset ALPHA 12374=NOTVALID BETA &&' $ENV_SHOW
exec_test 'export STUFF && unset STUFF &&' $ENV_SHOW
exec_test 'export MORE=4320 && unset MORE &&' $ENV_SHOW
exec_test 'export HELLO=WORLD && unset HELLO= &&' $ENV_SHOW
exec_test 'export one=1 two=2 && unset two one=1 && export one=$two &&' $ENV_SHOW
exec_test 'export a b c && unset b && export a=5 b=3 c=5 && unset a 7774 b &&' $ENV_SHOW
exec_test 'export AAAAA && unset AAAAA && unset AAAAA && export AAAAA=50 &&' $ENV_SHOW
exec_test 'export stuf=3 sheesh && unset stuff && export sheesh=5 && unset stuf &&' $ENV_SHOW

# CD TESTS
printf $BOLDYELLOW"\nCD AND PWD\n"$RESET
sleep $PAUSE
exec_test 'cd .. && pwd'
exec_test 'cd /Users && pwd'
exec_test 'cd && pwd'
exec_test 'cd ././././././././././././././././././././././././././././././ && pwd'
exec_test 'cd && pwd'
exec_test 'cd BACKROOMS && pwd'
exec_test 'cd /bin /etc && pwd'
exec_test 'cd /idk /bin && pwd'
exec_test 'cd / && pwd'
exec_test 'cd /////////////// && pwd'
exec_test 'cd ... && pwd'
exec_test 'cd ./../... && pwd'
exec_test 'mkdir t && cd t && pwd && cd .. && pwd && cd t && pwd && cd .. && rmdir t && pwd'
exec_test 'cd cd cd cd cd cd cd && pwd'
exec_test 'cd ../../../../../../../../../../../../../../../.. && pwd'
exec_test 'cd /../ && pwd'
exec_test 'cd /./././. && pwd'
exec_test 'cd .................... && pwd'
exec_test '               cd . && pwd'
exec_test '          cd'
# wtf
#exec_test 'mkdir test_dir && cd test_dir && rm -rf ../test_dir && cd . && pwd && cd . && pwd && cd .. && pwd'

# RELATIVE PATH
printf $BOLDYELLOW"\nCOMMAND WITH RELATIVE PATH\n"$RESET
sleep $PAUSE
exec_test 'ls'
exec_test 'lsblk'
exec_test 'whoami'
exec_test 'who'
exec_test 'w'
exec_test 'hostname'
exec_test 'dir'
exec_test 'uname'
exec_test 'arch'
exec_test 'true'
exec_test 'false'
exec_test 'du'
exec_test 'df'
exec_test ''
exec_test ' '
exec_test '           '
exec_test '			'
exec_test 'ls -a'
exec_test 'ls -l'
exec_test 'ls -la'
exec_test 'ls --full-time'
exec_test 'ls -l --author'
exec_test 'ls -bANaNa'
exec_test 'uname -a'
exec_test 'uname -a -m -p'
exec_test 'uname --hardware-platform'
exec_test 'seq 1'
exec_test 'seq 5'
exec_test 'seq 100'
exec_test 'seq 1 10'
exec_test 'seq -50 50'
exec_test 'seq 0 5 100'
exec_test 'seq -0.42 0.5 42'
exec_test 'seq -s -42 42'
exec_test 'seq -s- -20 20'
exec_test 'seq --separator=SEPARATOR -3 0.1 3'
exec_test 'touch ./tmpfile'
exec_test 'chmod 777 tmpfile'
exec_test 'cat tmpfile'
exec_test 'cp tmpfile ./tmpfile2'
exec_test 'rm -rf tmpfile'
exec_test 'rm -rf tmpfile2'
exec_test 'touch infile'
exec_test 'touch midfile'
exec_test 'touch outfile'
exec_test 'chmod 000 midfile'

# PATH
printf $BOLDYELLOW"\nCOMMAND WITH DIFFERENT PATH\n"$RESET
sleep $PAUSE
exec_test 'unset PATH && ls'
exec_test 'unset PATH && lsblk'
exec_test 'unset PATH && whoami'
exec_test 'unset PATH && who'
exec_test 'unset PATH && w'
exec_test 'unset PATH && hostname'
exec_test 'unset PATH && dir'
exec_test 'unset PATH && uname'
exec_test 'unset PATH && arch'
exec_test 'unset PATH && du'
exec_test 'unset PATH && df'
exec_test 'unset PATH && '
exec_test 'unset PATH &&  '
exec_test 'unset PATH &&            '
exec_test 'unset PATH && 			'
exec_test 'unset PATH && ls -a'
exec_test 'unset PATH && ls -l'
exec_test 'unset PATH && ls -la'
exec_test 'unset PATH && ls --full-time'
exec_test 'unset PATH && ls -l --author'
exec_test 'unset PATH && ls -bANaNa'
exec_test 'unset PATH && uname -a'
exec_test 'unset PATH && uname -a -m -p'
exec_test 'unset PATH && uname --hardware-platform'
exec_test 'unset PATH && seq 1'
exec_test 'unset PATH && seq 5'
exec_test 'unset PATH && seq 100'
exec_test 'unset PATH && seq 1 10'
exec_test 'unset PATH && seq -50 50'
exec_test 'unset PATH && seq 0 5 100'
exec_test 'unset PATH && seq -0.42 0.5 42'
exec_test 'unset PATH && seq -s -42 42'
exec_test 'unset PATH && seq -s- -20 20'
exec_test 'unset PATH && seq --separator=SEPARATOR -3 0.1 3'
exec_test 'unset PATH && touch ./tmpfile'
exec_test 'unset PATH && chmod 777 tmpfile'
exec_test 'unset PATH && cat tmpfile'
exec_test 'unset PATH && cp tmpfile ./tmpfile2'
exec_test 'unset PATH && rm -rf tmpfile'
exec_test 'unset PATH && rm -rf tmpfile2'
exec_test 'unset PATH && touch infile'
exec_test 'unset PATH && touch midfile'
exec_test 'unset PATH && touch outfile'
exec_test 'unset PATH && chmod 000 midfile'
exec_test 'mkdir dir1 && ls || ls'
exec_test 'mkdir dir2 && ls || ls'
exec_test 'touch dir1/lol'
exec_test 'touch dir2/lol'
exec_test 'echo "#!/bin/bash" > dir1/lol && echo "#!/bin/bash" > dir2/lol'
exec_test 'echo "echo ME IN DIR 1" >> dir1/lol && echo "echo ME IN DIR 2" >> dir2/lol'
exec_test 'chmod 777 dir1/lol'
exec_test 'chmod 777 dir2/lol'
exec_test 'export PATH="$PWD/dir1:$PWD/dir2" && lol &&' $ENV_SHOW
exec_test 'export PATH="$PWD/dir2:$PWD/dir1" && lol &&' $ENV_SHOW
exec_test 'export PATH="dir1:dir2" && lol &&' $ENV_SHOW
exec_test 'export PATH="dir2:dir1" && lol &&' $ENV_SHOW
exec_test 'export PATH="" && lol ||' $ENV_SHOW

# REDIRECTIONS
printf $BOLDYELLOW"\nREDIRECTIONS\n"$RESET
sleep $PAUSE
exec_test 'echo test > ls && cat ls'
exec_test 'echo test > ls >> ls >> ls && echo test >> ls&& cat ls'
exec_test '> lol echo test lol&& cat lol'
exec_test '>lol echo > test>lol>test>>lol>test mdr >lol test >test&& cat test'
exec_test 'cat < ls'
exec_test 'cat < ls > ls'
exec_test 'touch infile'
exec_test 'chmod 666 infile'
exec_test 'echo "RANDOM STUFF BRB" > infile'
exec_test 'touch outfile'
exec_test 'chmod 777 outfile'
exec_test '< infile cat'
exec_test 'ls > outfile'
exec_test 'ls > midfile > outfile'
exec_test 'echo > outfile && lsblk > newfile >> outfile'
exec_test 'echo > fourfile && pwd >> onefile >> twofile > threefile >> fourfile'
exec_test 'chmod 000 twofile'
exec_test '< twofile cat > threefile'
exec_test 'echo amogus > threefile'
exec_test '< threefile cat > onefile'
exec_test '< twofile < threefile cat'
exec_test '< threefile < twofile cat'
exec_test '< threefile < onefile cat'
exec_test '< onefile < threefile cat'
exec_test '< onefile < twofile < threefile cat'
exec_test '< onefile < whatfile cat'
exec_test '< whatfile < onefile cat'
exec_test '< onefile < threefile < fourfile cat'
exec_test 'lsblk > onefile > twofile > threefile'
exec_test '< infile cat > outfile'
exec_test 'echo AMOGUS > infile > outfile > infile > outfile > infile > outfile'
exec_test 'cd numbers || mkdir numbers && echo $?'
exec_test 'cd numbers && echo LOL > 1 > 2 > 3 > 4 > 5 > 6 > 7 > 8 > 9 >> 10 >> 11 >> 12 >> 13 >> 14 > 15 > 16 >> 17 > 18 >> 19 > 20 && ls && cat *'
exec_test 'echo SHEESH > infile && < infile cat > outfile'
exec_test '< midfile cat > midfile'
exec_test 'echo amogus > /dev/full'
exec_test 'pwd > /dev/full'
exec_test 'env > /dev/full'
exec_test 'export > /dev/full'

# PIPE TESTS
printf $BOLDYELLOW"\nPIPES\n"$RESET
sleep $PAUSE
exec_test 'cat tests/lorem.txt | grep arcu | cat -e'
exec_test 'echo test | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e| cat -e| cat -e| cat -e| cat -e| cat -e| cat -e| cat -e| cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e|cat -e'
exec_test 'lsblk | head -c 100 | wc -c'
exec_test 'ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls'
exec_test 'ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls|ls'
exec_test 'lsblk > infile && < infile cat | cat -e | wc > outfile'
exec_test '< infile cat | grep "n" | cat -e | cat -e > outfile'
exec_test 'ls | head > outfile > outfile'
exec_test 'yes | head -100 | head -50 | head -10'
exec_test 'sleep 0.5 | sleep 0.1 | sleep 0.3'
exec_test 'sleep 0.1 | sleep 0.2 | sleep 0.3 | sleep 0.4 | sleep 0.5'
exec_test 'sleep 0.5 | sleep 0.4 | sleep 0.3 | sleep 0.2 | sleep 0.1'
exec_test 'cat < /dev/urandom | head -100 | grep "a" | wc'
exec_test 'echo SUS | echo NOTSUS | echo SUS'
exec_test 'pwd | wc'
exec_test 'pwd | echo lol | env | wc'
exec_test 'lsblk | lsblk | lsblk'
exec_test '< /dev/urandom cat | head -200 > /dev/null'
exec_test 'yes | head > /dev/full'
exec_test 'yes GET OUT OF MY HEAD | cat | cat | cat | cat | cat | cat | cat | cat | cat | cat | cat | cat | cat | cat | cat | cat | cat | cat | cat | cat | cat | cat | cat | cat | cat | cat | cat | cat | cat | cat | cat | cat | cat | cat | cat | cat | cat | cat | cat | cat | cat | cat | cat | cat | cat | cat | cat | cat | cat | cat | cat | cat | cat | cat | cat | cat | cat | cat | cat | cat | cat | cat | cat | cat | cat | cat | cat | cat | cat | cat | cat | cat | head -100'

# ENVIRONMENT VARIABLES
printf $BOLDYELLOW"\nENVIRONMENT VARIABLES\n"$RESET
sleep $PAUSE
MYVARS='export amogus=42 sheesh=hello sus=222 lol= lmao="" yeet &&'
exec_test $MYVARS 'export amogus=42 sheesh=hello sus=222 lol="0" lmao="" yeet'
exec_test $MYVARS 'echo $amogus'
exec_test $MYVARS 'echo "$sheesh"'
exec_test $MYVARS 'echo $lol $lmao'
exec_test $MYVARS 'echo $yeet$amogus$sheesh'
exec_test 'echo $'
exec_test 'echo $USER'
exec_test 'echo $USER $PWD'
exec_test 'echo "$USER"'
exec_test 'echo $HOME $PWD $lol $sus'
exec_test '$IDONTEXIST'
exec_test 'echo $MENEITHER'

# AND OR
printf $BOLDYELLOW"\nAND OR\n"$RESET
sleep $PAUSE
exec_test 'echo hello && echo world'
exec_test 'echo hello && echo world && echo kthxbye'
exec_test 'echo AAAAA && echo AAAAA && echo AAAAA && echo AAAAA && echo AAAAA && echo AAAAA && echo AAAAA && echo AAAAA && echo AAAAA && echo AAAAA && echo AAAAA && echo AAAAA && echo AAAAA && echo AAAAA && echo AAAAA && echo AAAAA && echo AAAAA && echo AAAAA && echo AAAAA && echo AAAAA && echo AAAAA && echo AAAAA && echo AAAAA && echo AAAAA && echo AAAAA && echo AAAAA && echo AAAAA && echo AAAAA && echo AAAAA && echo AAAAA && echo AAAAA && echo AAAAA && echo AAAAA && echo AAAAA && echo AAAAA && echo AAAAA && echo AAAAA && echo AAAAA && echo AAAAA && echo AAAAA && echo AAAAA && echo AAAAA && echo AAAAA && echo AAAAA && echo AAAAA && echo AAAAA && '
exec_test 'cat LOL && echo STUFF'
exec_test 'cat LOL && echo STUFF && echo HELLO'
exec_test 'ECHO HELLO && echo hello && ECHO WORLD && echo world'
exec_test 'cat IDK && echo HEY cat IDK && echo HEY cat IDK && echo HEY cat IDK && echo HEY cat IDK && echo HEY cat IDK && echo HEY cat IDK && echo HEY cat IDK && echo HEY'
exec_test 'echo 4242 && cat 8484 && echo 4242 && cat 8484 && echo 4242 && cat 8484 && echo 4242 && cat 8484 &&echo 4242 && cat 8484'
exec_test 'pwd && ls ls && ls ls && pwd && ls ls && pwd && pwd && ls ls && ls ls && pwd && pwd && ls ls && pwd && ls ls && ls ls && pwd'
exec_test 'true && false && true && false && true && false && true && false && true && echo SHEESH'
exec_test 'who&& aejiof&& aejfio&& false&& hostname&& uname&& du&& lsblk&& echo&& ajefoia&& arch&& aejfio&& whoami&& echo&& aehjio&& w&& hello&& df&& ajeiofaj&& true&& cat aejfi&& ls aejfl&& pwd&& ls&& dir'
exec_test 'wtf && uname && whoami && HEHEHEHE && cat aejfi && gibberish && who && echo && my && true && ls && YOYOYO && hello && KTHXBYE && lsblk && echo sheesh && lsblk && arch && lsblk && du && ls whatever && who && wtf && whoami && arch && SHEEEEEEEEEEEESH && lsblk && IHASVALUE && echo amogus && lsblk && ls && dir && uname && HEY && w && IDONTEXIST && garbage && echo hello && echo && pwd && who && false && hello && ls aejfl && pwd && smh && df && idontexist && pwd && arch && ls && ls && pwd && uname && world && wtf && hostname'
exec_test 'wtf && arch && echo && hostname && lsblk && KTHXBYE && lsblk && YOYOYO && HEHEHEHE && pwd && uname && garbage && pwd && world && HEY && dir && who && who && my && SHEEEEEEEEEEEESH && echo amogus && uname && ls && who && ls && uname && lsblk && arch && lsblk && IDONTEXIST && ls && ls aejfl && arch && gibberish && pwd && hello && w && df && ls && hello && wtf && smh && whoami && pwd && IHASVALUE && ls whatever && true && cat aejfi && false && echo sheesh && echo && wtf && du && echo hello && whoami && lsblk && idontexist'

exec_test 'echo hello || echo world'
exec_test 'echo hello || echo world || echo kthxbye'
exec_test 'echo AAAAA || echo AAAAA || echo AAAAA || echo AAAAA || echo AAAAA || echo AAAAA || echo AAAAA || echo AAAAA || echo AAAAA || echo AAAAA || echo AAAAA || echo AAAAA || echo AAAAA || echo AAAAA || echo AAAAA || echo AAAAA || echo AAAAA || echo AAAAA || echo AAAAA || echo AAAAA || echo AAAAA || echo AAAAA || echo AAAAA || echo AAAAA || echo AAAAA || echo AAAAA || echo AAAAA || echo AAAAA || echo AAAAA || echo AAAAA || echo AAAAA || echo AAAAA || echo AAAAA || echo AAAAA || echo AAAAA || echo AAAAA || echo AAAAA || echo AAAAA || echo AAAAA || echo AAAAA || echo AAAAA || echo AAAAA || echo AAAAA || echo AAAAA || echo AAAAA || echo AAAAA || '
exec_test 'cat LOL || echo STUFF'
exec_test 'cat LOL || echo STUFF || echo HELLO'
exec_test 'ECHO HELLO || echo hello || ECHO WORLD || echo world'
exec_test 'cat IDK || echo HEY cat IDK || echo HEY cat IDK || echo HEY cat IDK || echo HEY cat IDK || echo HEY cat IDK || echo HEY cat IDK || echo HEY cat IDK || echo HEY'
exec_test 'echo 4242 || cat 8484 || echo 4242 || cat 8484 || echo 4242 || cat 8484 || echo 4242 || cat 8484 ||echo 4242 || cat 8484'
exec_test 'pwd || ls ls || ls ls || pwd || ls ls || pwd || pwd || ls ls || ls ls || pwd || pwd || ls ls || pwd || ls ls || ls ls || pwd'
exec_test 'true || false || true || false || true || false || true || false || true || echo SHEESH'
exec_test 'who|| aejiof|| aejfio|| false|| hostname|| uname|| du|| lsblk|| echo|| ajefoia|| arch|| aejfio|| whoami|| echo|| aehjio|| w|| hello|| df|| ajeiofaj|| true|| cat aejfi|| ls aejfl|| pwd|| ls|| dir'
exec_test 'wtf || uname || whoami || HEHEHEHE || cat aejfi || gibberish || who || echo || my || true || ls || YOYOYO || hello || KTHXBYE || lsblk || echo sheesh || lsblk || arch || lsblk || du || ls whatever || who || wtf || whoami || arch || SHEEEEEEEEEEEESH || lsblk || IHASVALUE || echo amogus || lsblk || ls || dir || uname || HEY || w || IDONTEXIST || garbage || echo hello || echo || pwd || who || false || hello || ls aejfl || pwd || smh || df || idontexist || pwd || arch || ls || ls || pwd || uname || world || wtf || hostname'
exec_test 'wtf || arch || echo || hostname || lsblk || KTHXBYE || lsblk || YOYOYO || HEHEHEHE || pwd || uname || garbage || pwd || world || HEY || dir || who || who || my || SHEEEEEEEEEEEESH || echo amogus || uname || ls || who || ls || uname || lsblk || arch || lsblk || IDONTEXIST || ls || ls aejfl || arch || gibberish || pwd || hello || w || df || ls || hello || wtf || smh || whoami || pwd || IHASVALUE || ls whatever || true || cat aejfi || false || echo sheesh || echo || wtf || du || echo hello || whoami || lsblk || idontexist'

exec_test 'ls -la && ls -lh || ls -l'
exec_test 'cat file.txt && tail -n 5 file.txt || head -n 5 file.txt'
exec_test 'mv oldfile.txt newfile.txt && cp file.txt file_copy.txt || rm file.txt'
exec_test 'df -h && du -sh || find . -name "*.txt"'

exec_test 'echo LOL && cat LOL || echo LOL || cat LOL && echo LOL && cat LOL && echo LOL || cat LOL && echo LOL || cat LOL || echo LOL && cat LOL || echo LOL && cat LOL && echo LOL && cat LOL || echo LOL || cat LOL && echo LOL && cat LOL && echo LOL && cat LOL && echo LOL || cat LOL && echo LOL || cat LOL || echo LOL && cat LOL && echo LOL || cat LOL && echo LOL && cat LOL || echo LOL && cat LOL && echo LOL || cat LOL && echo LOL && cat LOL && echo LOL && cat LOL'
exec_test 'echo HI && cat LOL || ls KTHXBYE && pwd || lsblk || NUTS || whoami || echo BYEBYE && echo HI && pwd && lsblk || NUTS || cat LOL && whoami || echo BYEBYE || ls KTHXBYE && echo HI || pwd && lsblk && NUTS || cat LOL || whoami && echo BYEBYE'
exec_test 'echo HI && cat LOL || ls KTHXBYE || pwd && lsblk || NUTS && whoami || echo BYEBYE && echo HI || pwd || ls KTHXBYE && cat LOL && lsblk || NUTS && whoami || echo BYEBYE && pwd || ls KTHXBYE && cat LOL || lsblk || NUTS || whoami && echo BYEBYE || echo HI && pwd || ls KTHXBYE || cat LOL || lsblk && NUTS && whoami || echo BYEBYE'

# SUBSHELLS
printf $BOLDYELLOW"\nSUBSHELLS\n"$RESET
sleep $PAUSE
exec_test '(touch file1.txt && touch file2.txt)'
exec_test '(touch output.txt)'
exec_test 'ls -la | grep "\.txt" && (cat file1.txt | grep "pattern" > output.txt || echo "pattern not found in file1.txt") && (cat file2.txt | grep "pattern" >> output.txt || echo "pattern not found in file2.txt")'
exec_test 'ls -la | grep "\.txt" && (cat file1.txt | grep "pattern" > output.txt || echo "pattern not found in file1.txt") && (cat file2.txt | grep "pattern" >> output.txt || echo "pattern not found in file2.txt")'
exec_test 'find . -name "*.txt" | xargs grep -l "pattern" > output.txt && (cat output.txt | wc -l || echo "no matching files found") && rm output.txt'
exec_test 'cat file1.txt file2.txt | sort | uniq -c | sort -nr | head -n 10 > top_ten.txt && (cat top_ten.txt || echo "input files are empty")'
exec_test '((echo "first subshell" && (echo "second subshell" || echo "second subshell failed")) || (echo "first subshell failed" && (echo "second subshell" || echo "second subshell failed"))) && (echo "both subshells succeeded" || echo "at least one subshell failed")'
exec_test 'true && (touch top_ten.txt)'
exec_test 'cat file1.txt file2.txt | sort | uniq -c | sort -nr | head -n 10 > top_ten.txt && ((cat top_ten.txt | wc -l && (cat top_ten.txt || echo "input files are empty")) || (echo "no matching lines found" > top_ten.txt && cat top_ten.txt))'
exec_test '(cat file1.txt file2.txt | sort | uniq -c | sort -nr | head -n 10 && (echo "top 10 lines found" || echo "input files are empty")) > top_ten.txt && ((cat top_ten.txt | wc -l || echo "no matching lines found") && (pwd && ls))'
exec_test '(uname -a && pwd && lsblk) | sort | head -n 1 | (grep -q "Linux" && (echo "system is Linux" && (cat file.txt | grep "pattern" | wc -l > count.txt || echo "pattern not found in file.txt")) || (echo "system is not Linux" && (tail -n 10 file.txt > last_ten.txt || echo "file.txt has less than 10 lines"))) && (cat count.txt && cat last_ten.txt)'
exec_test '(echo 1 && echo 2 && echo 3) | cat -e | cat -e | (cat -e && (echo 4 && (echo 5 | cat -e | cat -e > count.txt || echo 6)) || (echo 7 && (echo 8 > last_ten.txt || echo 9))) && (echo 10 && echo 11)'
exec_test 'echo 1 | (echo 2 && (echo 3 && (echo 4 | cat -e)) || (echo 5 && (echo 6)))'
exec_test 'echo 1 | (echo 2 | echo 3)'

# WILDCARD
printf $BOLDYELLOW"\nWILDCARD\n"$RESET
sleep $PAUSE
exec_test 'echo *'
exec_test 'echo * *'
exec_test 'echo * * *'
exec_test 'cat *'
exec_test 'echo *e*'
exec_test 'echo *o*'
exec_test 'echo *i*'
exec_test 'echo *u*'
exec_test 'echo *a*'
exec_test 'echo "*"'
exec_test 'echo "* *"'
exec_test 'echo "*e"'
exec_test 'echo "*"e*'
exec_test 'echo *e"*"'
exec_test 'echo *"*"*'
exec_test 'echo ***'
exec_test 'echo i*e'
exec_test 'echo o*e'
exec_test 'echo e*e'
exec_test 'echo *A *A* A* *a *a* a*'
exec_test 'echo *B *B* B* *b *b* b*'
exec_test 'echo *C *C* C* *c *c* c*'
exec_test 'echo *D *D* D* *d *d* d*'
exec_test 'echo *E *E* E* *e *e* e*'
exec_test 'echo *F *F* F* *f *f* f*'
exec_test 'echo *G *G* G* *g *g* g*'
exec_test 'echo *H *H* H* *h *h* h*'
exec_test 'echo *I *I* I* *i *i* i*'
exec_test 'echo *J *J* J* *j *j* j*'
exec_test 'echo *K *K* K* *k *k* k*'
exec_test 'echo *L *L* L* *l *l* l*'
exec_test 'echo *M *M* M* *m *m* m*'
exec_test 'echo *N *N* N* *n *n* n*'
exec_test 'echo *O *O* O* *o *o* o*'
exec_test 'echo *P *P* P* *p *p* p*'
exec_test 'echo *Q *Q* Q* *q *q* q*'
exec_test 'echo *R *R* R* *r *r* r*'
exec_test 'echo *S *S* S* *s *s* s*'
exec_test 'echo *T *T* T* *t *t* t*'
exec_test 'echo *U *U* U* *u *u* u*'
exec_test 'echo *V *V* V* *v *v* v*'
exec_test 'echo *W *W* W* *w *w* w*'
exec_test 'echo *X *X* X* *x *x* x*'
exec_test 'echo *Y *Y* Y* *y *y* y*'
exec_test 'echo *Z *Z* Z* *z *z* z*'
exec_test 'echo "*A *A* A*" *a *a* a*'
exec_test 'echo *B *B* "B* *b *b"* b*'
exec_test 'echo *C *C* C* "*c *c* "c*'
exec_test 'echo *D *D"* D* "*d *d* d*'
exec_test 'echo *E *E* "E* *e" *e* e*'
exec_test 'echo *"F *F* F*" *f *f* f*'
exec_test 'echo *G "*G* G* *g *g* "g*'
exec_test 'echo *H *H* "H* "*h *h* h*'
exec_test 'echo *I *"I* I* *i *i* "i*'
exec_test 'echo "*J *J* J*" *j *j* j*'
exec_test 'echo *K *K* K*" *k *k* "k*'
exec_test 'echo *L *L* L* "*l "*l* l*'
exec_test 'echo *M *M* ""M* *m *m* m*'
exec_test 'echo "*N *N* N*" *n *n* n*'
exec_test 'echo *O *O* O* *o *o*" "o*'
exec_test 'echo *P *"P* P* "*p *p* p*'
exec_test 'echo *Q *Q*" Q* *q "*q* q*'
exec_test 'echo "*R *R* R*" *r *r* r*'
exec_test 'echo *S *S* "S* *s "*s* s*'
exec_test 'echo *T *T* T* "*t *t* "t*'
exec_test 'echo *U *U* U* "*u "*u* u*'
exec_test 'echo *V *V* V*" *v *v* "v*'
exec_test 'echo "*W *W* W*" *w *w* w*'
exec_test 'echo *X *X* X* *x "*x* "x*'
exec_test 'echo *Y *Y* Y"* "*y *y* y*'
exec_test 'echo *Z *Z* Z* *z "*z* "z*'

# SYNTAX ERROR
printf $BOLDYELLOW"\nSYNTAX ERROR\n"$RESET
exec_test '&&&& test'
exec_test '| test'
exec_test '$JFOJEIO'
exec_test '&& $ESFJOIEJ &&'
exec_test 'echo > <'
exec_test 'echo | |'
exec_test '<'
exec_test 'echo )()('
exec_test '< cat'
exec_test 'cat < | HELLO'
exec_test '|||||'
exec_test '( ͡° ͜ʖ ͡°)'
exec_test '(echo stuff))'
exec_test '((whereis my parentheses)'
exec_test 'cat file1 && cat file2 ||'
exec_test 'grep "pattern" file1 | grep "pattern" file2 <'
exec_test 'echo "message" >> file1 <<'
exec_test 'sort file1 > file2)'
exec_test '(cat file1 | sort > file2'
exec_test 'cat file1 && || cat file2'
exec_test 'grep "pattern" file1 < | grep "pattern" file2'
exec_test 'echo "message" << >> file1'
exec_test 'sort file1 ) > file2'
exec_test 'cat file1 | sort > file2 ('