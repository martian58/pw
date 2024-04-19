void you_lost() {
    // Clear screen.
    printf("\033c");
    // Define color codes.
    const char *colors[] = {"34", "32", "33", "36", "35"};

    // ASCII art lines.
    const char *lines[] = {
    "@@       @@  @@@@@@@@  @@    @@           @@            @@@@@@@@   @@@@@@@@@@   @@@@@@@@@@@@    @@ @@    ",
    " @@     @@   @@    @@  @@    @@           @@            @@    @@   @@                @@         @@ @@    ",
    "  @@   @@    @@    @@  @@    @@           @@            @@    @@   @@@@@@@@@         @@         @@ @@   ",
    "   @@ @@     @@    @@  @@    @@           @@            @@    @@          @@         @@         @@ @@     ",
    "    @@@      @@    @@  @@    @@           @@            @@    @@          @@         @@         @@ @@     ",
    "    @@@      @@@@@@@@  @@@@@@@@           @@@@@@@@@@@   @@@@@@@@   @@@@@@@@@@        @@                 ",
    "    @@@      @@@@@@@@  @@@@@@@@           @@@@@@@@@@@   @@@@@@@@   @@@@@@@@@@        @@         @@ @@ :(",
    };

    // Print each line with color transition and a random character.
    printf("\n\n");
    for (int i = 0; i < 8; i++) {
        char line_copy[strlen(lines[i]) + 1];
        strcpy(line_copy, lines[i]);
        char rnd_char = '@';
        for (int j = 0; line_copy[j] != '\0'; j++) {
            if (line_copy[j] == '@') {
                line_copy[j] = rnd_char;
            }
        }
        print_colored_line(line_copy, colors[i % 5], colors[(i + 1) % 5]);
        usleep(200000); // Sleep for 0.2 seconds.
    }

    printf("\n\n");
}