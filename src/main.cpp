#include "Card.h"
#include "utils.h"
#include <iostream>

int main() {
  int num_wins = 0;
  int num_sims = 10000;
  int min_number_of_calls = 75;

  for (int n = 0; n < num_sims; ++n) {
    Card card{};          
    card.n_squares[2].daub();
    auto balls = get_shuffled_integers(1, 75, 75);
    for (int i = 1; i <= balls.size(); ++i) {
      card.update(balls[i - 1]);
      if (card.is_a_winner(Game::RotatingL)) {
        std::cout << i << "\n";
        min_number_of_calls = std::min(i, min_number_of_calls);
        break;
      }
    }
  }
  std::cout << min_number_of_calls << " \n";
}
