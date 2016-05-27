# IMPLEMENTATION

## Parser Module

The `parser` module is responsible for parsing messages recieved by one of the programs (field, guide, and server). By seperating this into it's own shared module, it means that if we change opcodes, it will be much easier to deal with, since we need only update one file and the program that respods to that message. It has one function

`char **parseMessage(char *message, int program)`

where `message` is the string to be parsed from the port, and int program is an enum representing FIELD_AGENT = 0, GUIDE_AGENT = 1, SERVER = 2. `parseMessage` returns an array of strings representing each field in the message seperated by the `|` character. 

`parseMessage` checks that:
* Every message contains a valId opcode.
* That the opcode is an appropriate one for the program calling it.
* That each message is correctly formatted.
# Each message is the correct length.

This way the programs don't need to worry in their code about incorrectly parsed programs.

A `NULL` return means an incorrectly formatted message was recieved, and may be logged in the log file.

### Psudeocode:

```c
int count = 0;
while (there are tokens left seperated by '|') {
	count++
	list_add(count, token)
}


make an array from the list

hashtable_t *ht = hashtable_get(program);
if ((int rightLength = hashtable_get(ht, array[0])) == NULL) then
	return NULL


if (count != rightLength)
	return NULL


return array

```

### Data Structures
First we'll make a `list` to read in from token.

We'll also need a `hashtable` that maps from opcodes to a strut that stores the the length of the opcode. This hashtable will be hard coded in as a const. There will be one of these hashtables for each program, and we'll map to each.


### Error Handling

The parser module never exits the program, but returns NULL when an error occurs.

### Resource Management

The array returned by the parser module should be freed by the program that calls the parser. The parser frees the list it uses.

### Persistent Storage

There is no persistent storage for the parser. It does not itself log any bad queries.


## Socket Module

The `socket` module handles creating, binding, reading from a socket, and sending to a socket for the `guide Agent` and `Server` modules. By abstracting this away, we can easily replace the socket IO with file IO, to make testing easier. The socket module has the following functions:

`int createSocket(struct in_addr addr, int port)`

which creates a socket at addres `in_addr` and port `port`, binds it for UDP traffic over IP, and returns the socket.

### Psuedocode:

```c

create IP socket
if (socket failed)
	throw error

bind to addr and port
if (bind failed)
	throw error

return socket

```

`int readMessage(int socket, char *message, sockaddr_in them)`

This function takes a socket, and calls `recvfrom`, putting the response in *message (meant to be `NULL`), and storing the sender in `them`. Here, if we want to swipe out a file input, we can using the C preproccessor. The `int` returned is the same as returned by `recvfrom`.

### Psuedocode:
```c
message = char[MESSAGESIZE]

if (reading from socket) {
	int nbytes = recvfrom(sock, message, MESSAGESIZE-1, 0, them, len)
	if (nbytes < 0)
		throw error
	return nbytes
} else {
	message = readline(file)
	return strlen(message)
}

```

`int sendMessage(int socket, char *message, sockaddr_in them)`

This function takes a socket, and sends the message to the given `sockaddr_in` using the given `socket`. The returned `int` is the same as the result when using the `sendto` function. Again, here we can nicely swithc out a file if we want.

### Psuedocode:

```c
if (sending through a socket)
	return sendto()
else if (writing to file)
	write to file
	return strlen(message)
```

### Data Structures
All data structures are passed in, except for any read files. If we are using a read file, the preprocessor will be used to compile the pgroam with a file pointer to some file used in testing.

### Error Handling

The parser module never exits the program, but returns NULL or -1 when an error occurs.

### Resource Management

The parser frees all memory it uses, except for the messages and sockets it passes back to be used by the main program.

### Persistent Storage

If we are using a read file, the preprocessor will be used to compile the program with a file pointer to some file used in testing.

The sockets module does not log anything by itself.

## Game Server

The `Game Server` has several different functions

* `main(const int argc, char *argv[])`

The main function runs overall program.

### Psuedocode
```c

struct Game *game = initialize(argc, argv);
while (current Time - game->startTime < game->gameLen) {
	struct sockaddr_in them = new_sockaddr_in;
	char *message = NULL;
	int nbytes = readMessage(game->socket, message, &them);
	if (nbytes < 0) {
		throw error;
		exit(4)
	} else {
		char *parsedMessage[] = parseMessage(message);
		handleMessage(parsedMessage, &them, game);
	}

	if (15sec passed) {
		updateDisplay(game);
	}
} 
gameOver(game)

```

* `struct Game *initialize(int argc, char *argv[])`

This function initializes the game server by creating a game Id and valIdating the arguments. It also reads in the drop file and sets the logging mode.

### Psuedocode:

```c

struct Game *game = malloc(sizeof(struct Game));
int place = 1;
if (arglen != 3 or arglen != 4) {
	printf("Incorrect number of arguments: usage is: ./gameserver [-log=raw] codeDropPath GSport\n ");
	exit(1);
} 

if (argv[place] == "-log=raw") {
	game->logRaw = true;
	place++;
}  else {
	game->logRaw = false;
}

if (argv[place] != SOME FILE) {
	throw error;
	exit(2)
} else {
	game->drops = hashtable_create();
	while ((char* drop = readline) != NULL) {
		hashtable_add(game->drops, drop[0], newlonglat(drop[1], drop[2]));
	}
}

if (game -> socket = createSocket() < 0) {
	throw error
	exit(3)
}

game->gameId = rand()%65535;
game->fieldAgents = hashtable_create();
game->teams = hashtable_create();
game->startTime = current time;
game->gameLength = some constant;

return game;

```

* `bool handleMessages(char *message[], struct Game *game)`

This function handles all the messages recieved by the server.

```c 
handleMessages(char *message[], sockaddr_in *them, struct Game *game) {
	if (strcmp(message[0], them, "FA_LOCATION")) {
		FALocation(message, game)
	} else if (strcmp(message[0], them, "FA_NEUTRALIZE")) {		
		FANeutralize(message, game)
	} else if (strcmp(message[0], them, "FA_CAPTURE")) {		
		FACapture(message, game)
	}  else if (strcmp(message[0], them,  "GA_NEUTRALIZE")) {		
		GANeutralize(message, game)
	}  else if (strcmp(message[0], them, "GA_HINT")) {		
		GAHint(message, game)
	}
}
```

* `bool FALocation(char **message, struct sockaddr_in *them, Game struct *game)`
This function handles the `FA_Location` opcode

### Psuedocode

```c
int gameId = sscanf("%d", message[1]);
if (gameId == EOF) {
	return false
}
char *pebbleId = message[2];
char *teamName = message[3];
char *playerName = message[4];
struct longlat *location = longlatFromString(message[5], message[6]);
if (NULL) {
	return false;
}
int statusRequest = sscanf("%d", message[1]);
if (statusRequest == EOF) {
	return false;
}


struct field_agent *fa = hashtable_get(game->fieldAgents, pebbleId);
if (gameId == 0) {
	if (fa == NULL) {
		create a new field_agent copying over all of the string values
		hashtable_add(game->fieldAgents, pebbleId, newFieldAgent);
		log
		sendmessage
	} else if (fa != NULL) {
		if (fa->captured) {
			return false;
		}
	}
}

if (game->gameId != gameId) {
	return false;
}
if (fa == NULL) {
	return false;
}

if (!strcmp(fa->team, teamName) || !strcmp(fa->playerName, playerName)) {
	return false;
}

fa->lastKnownLocation = location;

if (statusRequest = 1) {
	sendGameStatus(game, 0, pebbleId);
}
return true;

```

* `bool FANeutralize(char **message, struct sockaddr_in *them, Game struct *game)`
This function handles the `FA_Neutralize` opcode

### Psuedocode

```c
int gameId = sscanf("%d", message[1]);
if (gameId == EOF) {
	return false
}
char *pebbleId = message[2];
char *teamName = message[3];
char *playerName = message[4];
struct longlat *location = longlatFromString(message[5], message[6]);
if (NULL) {
	return false;
}
char *codeId = message[7];


if (game->gameId != gameId) {
	return false;
}
if (struct field_agent *fa = hashtable_get(game->fieldAgents, pebbleId) == NULL) {
	return false;
}

if (!strcmp(fa->team, teamName) || !strcmp(fa->playerName, playerName)) {
	return false;
}

if (struct drop *drop = hashtable_get(game->drop(codeId)) == NULL) {
	return false;
} else {
	if (longlatDistance(location, drop->location) < 10 && drop->neutralized == false) {
		drop->neutralized == false;
		sendMessage(game->socket, "GS_RESPONSE|" +gameId + "|" + MI_NEUTRALIZED", fa->address);
		hashtable_get(game->teams, teamName)->dropsNeutralized++;
	}
}
return true;

```

* `bool FACapture(char **message, struct sockaddr_in *them, Game struct *game)`
This function handles the `FA_Capture` opcode. It runs through as per the design instructions. The only weird thing it does is when it calls `hashtable_iterate` to look for the player with the right capture code. Here it passes in a copy of the `captureId` and when it finds the matching code, it changes it in place, so that the copied string comes back as a `pebbleId`, because it's hard to get an iterator to nicely send back data. 

### Psuedocode

```c
int gameId = sscanf("%d", message[1]);
if (gameId == EOF) {
	return false
}
char *pebbleId = message[2];
char *teamName = message[3];
char *playerName = message[4];
struct longlat *location = longlatFromString(message[5], message[6]);
if (NULL) {
	return false;
}
char *captureId = message[7];


if (game->gameId != gameId) {
	return false;
}
if (struct field_agent *fa = hashtable_get(game->fieldAgents, pebbleId) == NULL) {
	return false;
}

if (!strcmp(fa->team, teamName) || !strcmp(fa->playerName, playerName)) {
	return false;
}

if (struct field_agent *fa = hashtable_get(game->fieldAgents, pebbleId)) {
	return false;
} else {
	if (captureId = "0") {
		struct *radiusChecker rc = sizeof(radiusChecker);
		rc->location = location;
		rc->socket = game->socket;
		hashtable_iterate(game->fieldAgents, within10m, rc);
	} else {
		otherPebbleId = malloc(sizeof(char)* 5)
		hashtable_iterate(game->fieldAgents, sameCaptureCode, strcpy(otherPebbleId, captureId));
		if (strncmp(captureId, otherPebbleId, strlen(captureId))) {
			return false;
		}
		struct field_agent *capturedFA = hashtable_get(game->fieldAgents, otherPebbleId));
		if (capturedFA->lastCapture - currentTime() < 60s) {
			sendMessage(game->socket, "GS_RESPONSE|" +gameId + "|" + "MI_CAPTURED", capturedFA->address);
			sendMessage(game->socket, "GS_RESPONSE|" +gameId + "|" + "MI_CAPTURE_SUCCESS", fa->address);
			hashtable_get(game->teams, teamName)->numCaptures++;
			hashtable_get(game->teams, 
				hashtable_get(games->fieldAgents, otherPebbleId)->teamName))->numInactive++;
		}

	}
}
return true;
```

* `bool GAStatus(char **message, struct sockaddr_in *them, Game struct *game)`
This function handles the `GA_STATUS` opcode.

### Psuedocode

```c
int gameId = sscanf("%d", message[1]);
if (gameId == EOF) {
	return false
}
char *guideId = message[2];
char *teamName = message[3];
char *playerName = message[4];
int statusReq = sscanf("%d", message[5]);
if (statusReq == EOF) {
	return false
}

if (gameId == 0) {
	struct team *team = malloc(sizeof(struct team));
	team->playerNames = list_create();
	team->teamName = strcpy(teamName);
	struct Guide *guide = malloc(sizeof(struct Guide));
	guide->guideName = strcpy(playerName);
	guide->guideId = strcpy(guideId);
	guide->address = them;
	guide->lastTimeOfContact = currentTime;
	team->guide = guide;
	team->teamColor = some_random_Color;
	hashtable_add(game->teams, teamName, team);
	log
}

if (game->gameId != gameId) {
	return false;
}
if (struct team *team = hashtable_get(game->teams, teamName) == NULL) {
	return false;
}

if (!strcmp(team->guide->guideId, guideId) || !strcmp(team->guide->guideName, playerName)) {
	return false;
}

guide->lastTimeOfContact = currentTime;

if (statusReq == 1) {
	sendGameStatus(game, 1, teamName);
}

```

* `bool GAHint(char **message, struct sockaddr_in *them, Game struct *game)`
This function handles the `GA_HINT` opcode.

### Psuedocode

```c
int gameId = sscanf("%d", message[1]);
if (gameId == EOF) {
	return false
}
char *guideId = message[2];
char *teamName = message[3];
char *playerName = message[4];
char *pebbleId = message[5];
char *hintMessage = message[6];

if (game->gameId != gameId) {
	return false;
}
if (struct team *team = hashtable_get(game->teams, teamName) == NULL) {
	return false;
}

if (!strcmp(team->guide->guideId, guideId) || !strcmp(team->guide->guideName, playerName)) {
	return false;
}

struct hint *hintMessage = malloc(sizeof(struct hint));
hintMessage->messageRecieved = message;
hintMessage->messageRecieved = message;
hintMessage->recipient = pebbleId;
hintMessage->socket = game->socket;
hashtable_iterate(game->playerNames, sendHint, hint);
free(hintMessage);

```

`void within10m(void *arg, char *key, void *data)`
Iterator method for sending to eveything within 10m

Pseudocode:
```c
struct radiusChecker *rc = (struct radiusChecker*) arg;
struct fieldAgent *fa = (struct fieldAgent*) data;
(if longlatDistance(rc->location, fa->lastKnownLocation) < 10) {
	fa->lastCapture = currentTime();
	sendMessage(rc->socket, "GS_CAPTURE_ID|" + rc->gameId +"|"+ generateHexCode(), fa->address);
}
```

`void sameCaptureCode(void *arg, char *key, void *data)`
This is a helper iterator function which checks which things got the same capture code, and then stores it in the string passed.

Pseudocode:
```c
char *pebbleId = (char *) arg;
struct fieldAgent *fa = (struct fieldAgent*) data;

//We've already found the thing with the matching id. PebbleId's are longer than the 
if (strlen(pebbleId) > 4){
	return NULL;
} else {
	if (strcmp(data->captureCode, pebbleId)) {
		char *placeHolder = pebbleId;
		pebbleId = key;
		free(placeHolder);
}
```
`void sendHint(void *arg, char *key, void *data)`

This function is the iterator helper function for sending Hints to everything in the correct list.

Pseudocode:
```c
struct hint *hint = (struct hint*) arg;
struct fieldAgent *fa = (struct fieldAgent*) data;
if (strcmp(fa->teamName, hint->team)) {
	if (hint->recipient == * || hint->recipient == key) {
		sendMessage(rc->socket, hint->messageRecieved, fa->address);
	} 
}
```
`bool sendGameStatus(struct Game *game, int program, char * recipient)`
This sends the game status to the appropriate recipient, with 0 being `Field Agent` and 1 being `Guide Agent`.

Pseudocode:
```
char *message = "GAME_STATUS|" + gameId + "|"
if (recipient == 0) {
	struct fieldAgent *fa = hashtable_get(game->fieldAgents, recipient);
	struct sockaddr *them = fa->address;
	iterate over all the teams, adding the number of friendly operatives and foes
	iterate over all the drops, adding up the number of remaining drops
	append that to the message to be sent.
} else if (recipient == 1) {
	struct Guide *guide == hashtable_get(game->team, recipient) ->guide;
	struct sockaddr *them = guide->address; 
	iterave over every player adding their information to the message
	iterate over every drop
}

sendMessage(game->socket, them, message);
```

`bool gameOver(struct Game *game)`
This ends the game and sends the game over message to everyone
Pseudocode;
```c
iterate over drops - find the number remaining
iterate over players - find out how many remaining in each team
iterat over teams - find numNeutralized, Captured, and Captures.
Concatenate all the above strings.
iterate over field agents - sendthe Game_Over Message
iterate over guide agents - send the Game-Over message
```

`char *generateHexCode()`
Function which generates a random 4 digit hexadecimal code

Pseudocode:
```c
int r = rand() % 65536
char str[4]
return sprintf(str, "%04x", r);
```

`double longlatDistance(struct longlat *l1, struct longlat *l2) `
Finds the distance between two longlat pairs. The algorithm for this was taken from [this site](http://www.movable-type.co.uk/scripts/latlong.html), which states the scripts it provides are freely availible. 

Pseudocode:
```c
R = 6371*1000;
difflong= (l2->long - l1->long)*(M_PI/180)
difflat = (l2->lat - l1->lat)*(M_PI/180)
a = (sin(difflat/2))^2 + cos(l1->lat) * cos(l2->lat) * (sin(difflong/2))^2 
b = 2 * atan2( sqrt(a), sqrt(1-a) ) 
return R * b
```
All this was taken from


### Data structures (e.g., struct names and members)
*  The first data structure is a simple struct that keeps track of the game:

```c

struct Game {
	char *gameId;
	bool logRaw;
	FILE *fp logFile;
	hashtable_t *fieldAgents;
	hashtable_t *teams; 
	hashtable_t *drops;
	time_t startTime;
	double gameLength;
	int socket;
	GtkWidget *window;
	GtkWidge *image
}

```

the gameId tracks the generated game Id, then players is a hashmap from pebbleIds to a player struct and keeps track of every player, the teams hashtable maps from a char *teamName to a team struct,the drop maps from a the 4-digit hex code string of the drop to the associated drop struct, the starting time, the gameLength, and the UDP socket. We also need a palce to store our `Gtk` object to store the window we are displaying and the image.

* Next we want to think about the `fieldAgents. We chose to use the pebbleId as the unique key for the players because every message contains the pebbleId, and since playerNames come from a preconfigured list, there will likely be conflicts. Therefore the pebbleId has to be the unique key. Then we'll map from the pebbleId to some collection of data about the field_agent. We need to hold several different pieces of data about each field agent:

```c
struct fieldAgent {
    char *pebbleId;
    char *playerName;
    char *team;
	bool captured;
	struct longlat *lastKnownLocation;
	struct sockaddr address;
	time_t lastCapture;
	char *captureCode
}
```

We need all of these for various reasons. We need to store the pebbleId, playerName, and team to verify communications and allow the server and the guide agent to see where the players are; Then we need to know if the field_agent is "active" or has been "captured"; We need a place to store the last known location of the agent; how to send messages to the agent, and the last time we recieved a capture message from the agent, so that we can tell if they captured another agent within 60s of the capture request. We also need to store the last capture code sent out (if `NULL` that means the player has never been within 10 m of a capture);

* For storing teams, we want to map from team names to players and the associated guide, so that when we recieve the `GA_HINT` command we can check that the guide is correct and find out where to send the mesage. We also need somewhere to store all the teams. So `Game -> teams` should store a `hashtable_t` from a `char *teamName` to some kind of struct that stores all the neccesarry knowledge about a team. 

```c
struct team {
    char *teamName;
    struct *guide;
    GdkColor teamColor;
    int numCaptures;
    int numInactive;
    int dropsNeutralized;
}
```
Since there are probably only 2 - 4 players per team we can use a list, as a hashtable will have a higher overhead (and a very small hashtable has few advantages over a list). We store the color for display in the GUI interface.

* We need some sort of struct about the guide to store the guideName, and the guideId to make sure it's correct. We'll also need to store where to send messages to the guide.
```c
struct guide {
    char *guideName;
    char *guideId;
	struct sockaddr address;
	time_t lastTimeOfContact;
}
```

* We also need some sort of map to display graphically, which we can model as an array of of longlat points. And we'll place the necessary elements on it based off of the stored base point and scale.

* We also will build a little longlat Struct

```c
struct longlat {
	double lat;
	double long;
}
```

* We need a struct for our drops

```c

struct drop {
	longlat *location;
	bool neutralized;
}
```

We also need a struct for sending hints. We store a pointer to the game hashtable here, which is annoying, but we need a way to get the right address. We also need to know the socket.
```c
struct hint {
	char *recipient;
	char *team;
	char *messageRecieved;
	int socket;
}
```

We need another little struct that stores the socket and location for finding things withn 10m:
```c
struct radiusChecker{
	struct longlat *location;
	int socket;
	char *gameId;
}
```
### Security and privacy properties
### Error handling and recovery
### Resource management
### Persistant storage (files, database, etc)

