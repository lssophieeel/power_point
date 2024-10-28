#include "./syntax_analyzer.hpp"

bool syntax_analyzer::analyze(const std::vector<Token>& token_vec) {
    States current_state = States::START_STATE;
    bool continue_execution = false;
    try {
        for (const auto& token : token_vec) {
            switch (current_state) {
                case States::START_STATE:
                    if (token.type == Token::TokenType::WORD) {
                        current_state = States::WORD_STATE;
                    }
                    else throw syntax_error_exception();
                    break;

                case States::WORD_STATE:
                    if (token.type == Token::TokenType::OPTION) {
                        current_state = States::OPTION_STATE;
                    }
                    else if (token.type == Token::TokenType::SHAPE_OPTION) {
                        current_state = States::SHAPE_OPTION_STATE;
                    }
                    else if (token.type == Token::TokenType::END) {
                        return true;
                    }
                    else {
                        throw syntax_error_exception();
                    }
                    break;

                case States::OPTION_STATE:
                    if (token.type == Token::TokenType::VALUE) {
                        current_state = States::VALUE_STATE;
                    }
                    else {
                        throw syntax_error_exception();
                    }
                    break;

                case States::SHAPE_OPTION_STATE:
                    if (token.type == Token::TokenType::OPTION) {
                        current_state = States::OPTION_STATE;
                    }
                    else {
                        throw syntax_error_exception();
                    }
                    break;

                case States::VALUE_STATE:
                    if (token.type == Token::TokenType::VALUE) {
                        current_state = States::VALUE_STATE;
                    }
                    else if (token.type == Token::TokenType::OPTION) {
                        current_state = States::OPTION_STATE;
                    }
                    else if (token.type == Token::TokenType::END) {
                        return true;
                    }
                    else throw syntax_error_exception();
                    break;

                default:
                    throw unknown_exception();
                    break;

            }
        }
    }
    catch (const syntax_error_exception& e) {
        std::cerr << e.what() << std::endl;
        return false;
    }
    catch (const unknown_exception& e) {
        std::cerr << e.what() << std::endl;
        return false;
    }
    return false;
}
