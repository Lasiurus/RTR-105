# 2.nodarbība - Ievads Shell komandām un paņēmieniem.


1. Paņēmieni
   * ↓ un ↑ lai navigētu komandu izmantošanas vēsturi un nosacīta automātiskā aizpilde.
   * `Tab` poga priekš automātiskās aizpildes un lai redzētu iespējamās opcijas.


2. Kommandas
   * `uname` - OS noskaidrošana
   * `whoami` - Parāda esošā Shell lietotāja nosaukumu.
     * `id -un` = `whoami` (komandas dara to pašu)
   * `pwd` - **Print Working Directory**, lai uzzinātu, kurā directory atrodies pašlaik.
   * `ls` - Dod informāciju par failiem un mapēm konkrētajā sistēmā, kur `ls` bez argumentiem izprintē esošās mapes saturu, izņemot slēptos failus.
     * `ls /[Directory name]` - lai dabūtu saturu kādam konkrētam directory.
        * `ls -a` - Tas pats, bet parāda arī slēptos failus.
     * `ls -l` - parāda esošās mapes saturu detalizētā saraksta veidā.
        * `ls -la` - tas pats, bet parāda arī slēptos failus.
     * `ls ~` - izprintē saturu ierīces "mājas" mapei.
     * `ls -d */` - izprintē tikai mapes, jeb folderus.
     * `ls *` - Dod tagadējā folder un tajā esošo folder saturu.
     * `ls -s`- Izprintē mapes saturu un dod folderā esošo failu un citu folderu lielumus
     * `ls -t`- Dod mapes saturu to izmainīšanas datumu un laiku secībā.
     * `ls -[arguments]r` - "ls" komandas izvade, tikai pretējā secībā.
     * `ls >[fileName].txt` - Izvada IEPRIEKŠĒJĀS shell komandas printēto saturu txt failā, šis fails tiks radīts esošajā mapē.


   * `cd` - lai pārvietotos.
     * `cd ..` - Lai pārvietotos vienu directory līmeni atpakaļ.
     * `cd -` - Lai pārvietotos uz iepriekšējo directory līmeni neatkarīgi no attāluma starp tām.
     * `cd /[Directory name]` - Lai nokļūtu uz konkrētu mapi uz augšu vai leju.


3. Citas lietas
   * `.` pirms faila vai mapes apzīmē to, ka tas ir slēpts.
   * `~`, jeb tilde simbolizē home directory. Uz to var tikt ar `cd ~` vai `cd ~/`
