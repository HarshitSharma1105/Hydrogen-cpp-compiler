#include <fstream>
#include <iostream>
#include <optional>
#include <sstream>
#include <vector>

#include "generation.h"

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    std::string contents,path=argv[1];

    if (!path.ends_with(".hy")) {
        std::cout << "Error: File must have a .hy extension\n";
        exit(EXIT_FAILURE);
    }

     {
        std::stringstream contents_stream;
        std::fstream input(path, std::ios::in);
        contents_stream << input.rdbuf();
        contents = contents_stream.str();
     }
    
    Tokenizer tokenizer(std::move(contents));
    std::vector<Token> tokens = tokenizer.tokenize();

    Parser parser(std::move(tokens));
    std::optional<NodeProg> prog = parser.parse_prog();

    if (!prog.has_value()) {
        std::cerr << "Invalid program" << std::endl;
        exit(EXIT_FAILURE);
    }

    {
        Generator generator(prog.value());
        std::cout << generator.gen_prog();
    }

   

    return EXIT_SUCCESS;
}