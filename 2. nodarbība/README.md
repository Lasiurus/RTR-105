# 2.nodarbība - Ievads Shell komandām un paņēmieniem.


1. Paņēmieni
   * ↓ un ↑ lai navigētu komandu izmantošanas vēsturi un nosacīta automātiskā aizpilde.
   * `Tab` poga priekš automātiskās aizpildes un lai redzētu iespējamās opcijas.


2. Kommandas
   * `uname` - OS noskaidrošana
   * `whoami` - Parāda esošā Shell lietotāja nosaukumu.
     * `id -un` = `whoami` (komandas dara to pašu)
   * `pwd` - **Print Working Directory**, lai uzzinātu, kurā directory atrodies pašlaik.
   * `ls` - Dod informāciju par failiem un mapēm konkrētajā sistēmā, kur `ls` bez argumentiem izprintē esošās mapes saturu, kas nav ar tag *hidden*.
     * `ls /[Directory name]` - lai dabūtu saturu kādam konkrētam directory.
     * `ls -l` - parāda esošās mapes saturu detalizētā saraksta veidā
     * `ls -la` - tas pats, bet parāda arī slēptos failus.


   * `cd` - lai pārvietotos.
     * `cd ..` - Lai pārvietotos vienu directory līmeni atpakaļ.
     * `cd -` - Lai pārvietotos uz iepriekšējo directory līmeni neatkarīgi no attāluma starp tām.
     * `cd /[Directory name]` - Lai nokļūtu uz konkrētu mapi uz augšu vai leju.


3. Citas lietas
   * `.` pirms faila vai mapes apzīmē to, ka tas ir slēpts.
   * `~`, jeb tilde simbolizē home directory. Uz to var tikt ar `cd ~` vai `cd ~/`
