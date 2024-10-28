#include "tokenizer.hpp"

token Tokenizer::tokenizer(std::string input, token& token) {
    token.data_type = token.detect_data_type(input);
    if (std::regex_match(input, shape_option_regex)) {
        token.type = token::TokenType::SHAPE_OPTION;
    } 
    else if (std::regex_match(input, value_regex)) {  
        token.type = token::TokenType::VALUE;
    } 
    else if (std::regex_match(input, option_regex)) {
        token.type = token::TokenType::OPTION;
    } 
    else if (std::regex_match(input, word_regex)) {
        token.type = token::TokenType::WORD;
    } 
    else {
        std::cout << "Invalid token found: " << input << std::endl;
    }

    return token;
}


void Tokenizer::print(const token& token){
    switch (token.type) {
    case token::TokenType::OPTION:
        std::cout << "option\n";
        break;
    case token::TokenType::SHAPE_OPTION:
        std::cout << "shape option\n";
        break;
    case token::TokenType::WORD:
        std::cout << "word\n";
        break;
    case token::TokenType::END:
        std::cout << "end\n";
        break;
    case token::TokenType::VALUE:
        std::cout << "value\n";
        break;
    default:
        break;
    }
}
