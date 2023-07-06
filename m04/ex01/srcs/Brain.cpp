/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viferrei <viferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 17:43:00 by viferrei          #+#    #+#             */
/*   Updated: 2023/07/05 21:01:52 by viferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Brain.hpp"

/*--- CONSTRUCTORS AND DESTRUCTOR --------------------------------------------*/

Brain::Brain() {
	std::cout << "A" PURPLE " Brain " RESET "is in the making! Beautiful!"
		<< std::endl;
}
Brain::Brain(const Brain& copy) {
	*this = copy;
	std::cout << PURPLE "Brain " RESET "Copy constructor called" << std::endl;
}
Brain& Brain::operator=(const Brain& rhs) {
	if (this != &rhs)
		ideas = rhs.getIdeas();
	std::cout << PURPLE "Brain " RESET "Copy cassignment operator called"
		<< std::endl;
	return *this;
}
Brain::~Brain() {
}

std::string	Brain::_ideaPool[100] = {
	"Look at that squirrel! I must catch it!",
	"I hope there's a mud puddle somewhere. Time for a muddy adventure!",
	"Wow, so many interesting smells. I must sniff them all!",
	"Is that a tennis ball? I must claim it as my own!",
	"I wonder if there are any new doggie friends to play with today.",
	"Look at me, I'm the fastest dog in the park! Zoom zoom!",
	"I love the feeling of grass between my paws. It's so refreshing!",
	"I hope there's a frisbee flying through the air. I'll catch it!",
	"I'm ready to show off my best tricks. Watch me spin!",
	"Time to roll around in the grass and soak up the sunshine.",
	"I smell treats nearby. Maybe someone will share with me!",
	"I wonder if I can find a hidden treasure buried in the park.",
	"Look at those ducks in the pond. I wish I could swim like them!",
	"I'm the king/queen of the park. Everyone should bow down to me!",
	"I'll mark my territory on every tree I pass. It's my way of saying 'hello'.",
	"I hope there's a water fountain nearby. I'm feeling thirsty.",
	"Time to explore the bushes and see if any critters are hiding.",
	"I'll chase my own tail just for fun. Who needs a reason?",
	"I love the feeling of the wind in my fur as I run. It's exhilarating!",
	"Look, it's a doggie treat stand! I hope they have my favorite biscuits.",
	"I'll do some high jumps and show off my impressive agility.",
	"I smell barbecue. Maybe someone dropped a delicious hotdog!",
	"I'll play a game of hide-and-seek with my human. They'll never find me!",
	"I hope there's a doggie agility course. I'll show off my skills!",
	"Time to roll on my back and demand belly rubs from everyone I meet.",
	"I'm on a mission to collect as many sticks as possible. Stick hoarder mode activated!",
	"I'll leave my paw prints on every bench in the park. It's my way of leaving my mark.",
	"I hope there's a squirrel watching me. I'll put on a show!",
	"Time to play a game of tag with my doggie friends. I'm always the fastest!",
	"I'll practice my howling skills and serenade everyone in the park.",
	"I wish I could use the TV remote. I have so many shows I want to watch.",
	"What if I try speaking in hooman language? Will they understand me?",
	"I should try my paw at painting. Maybe I'm the next Picasso!",
	"I wonder if I can convince the squirrels to join my secret dance party.",
	"If I stand on my hind legs, maybe I can reach the cookies on the counter.",
	"What if I wear my human's clothes and pretend to be them? Can I fool the neighbors?",
	"I bet I could become a world-famous acrobat. Time to practice my jumps!",
	"I wonder what it feels like to be a cat. Can I borrow some of their grace?",
	"If I bark loudly enough, maybe I can communicate with aliens from outer space.",
	"I should try my luck at writing a novel. Maybe I have a hidden talent for storytelling.",
	"I wonder what would happen if I press all the buttons on the keyboard. Would it create a masterpiece?",
	"If I rearrange the furniture, maybe my humans will be pleasantly surprised when they return.",
	"I should put on a fashion show with all the socks I've collected. Who needs a runway?",
	"What if I start my own doggy cooking show? Who needs humans in the kitchen?",
	"I wonder if I can train the birds to bring me treats. They should work for me!",
	"If I practice my howling, maybe I'll attract a pack of cool doggy friends.",
	"I should dig a tunnel to the center of the Earth. Maybe I'll find buried treasures!",
	"What if I invent a new language that only dogs understand? The possibilities are endless!",
	"I wonder if I can solve complex mathematical problems. Time to become a canine genius!",
	"Is that a butterfly? I'll pretend I don't care, but secretly I'm plotting its demise.",
	"I don't need a leash like those dogs. I walk on my own terms, thank you very much.",
	"Ah, the sunbeam on that bench looks inviting. I'll claim it as my throne for a while.",
	"The park is a playground for lesser beings. I'm merely tolerating their presence.",
	"I could chase that ball if I wanted to, but it's much more amusing to watch the dogs do it.",
	"Humans try so hard to understand us, but they'll never truly grasp our enigmatic nature.",
	"Look at that dog trying to impress everyone with its tricks. Pathetic.",
	"The wind carries the scent of adventure. Maybe I'll wander off and see where it takes me.",
	"I'll sit here and observe the humans, pretending not to care while secretly judging their actions.",
	"Oh, another cat invading my territory. They should learn to stay in their own domain.",
	"I'll rub against this tree and leave my mark. The world must know I've been here.",
	"The park is my stage, and every step I take exudes grace and elegance.",
	"Dogs may have their loyalty, but I have my independence. Who's the smarter species now?",
	"I'll show off my superior balance by walking along this narrow fence. Dogs could never manage this.",
	"Humans think they're training me, but little do they know I'm merely humoring them.",
	"Look at those ducks in the pond. I could catch one if I wanted to, but it's more fun to watch them swim.",
	"I'll keep my distance from those pesky dogs. They're far too eager for my refined taste.",
	"This park is my kingdom, and everyone else is just living in it.",
	"I could climb that hill, but it's more amusing to watch the dogs struggle with their clumsy attempts.",
	"I'll brush against this person's legs and make them feel special. It's good to keep them on their toes.",
	"The world is my playground, and I'll explore it at my own leisure.",
	"Humans are so predictable. They'll never understand my sophisticated ways.",
	"I'm just napping here, pretending I care about your absence.",
	"I see you left some food in my bowl. Well, I guess I'll eat it.",
	"Why can't humans be more independent like us cats?",
	"I'll take this opportunity to knock some stuff off the shelves. It's my special talent.",
	"Humans think they own the place, but we all know who really rules here.",
	"I could use a good scratching session. Maybe I'll find a nice piece of furniture to ruin.",
	"I'll explore every corner of the house and ensure it's up to my standards.",
	"I wonder what the birds are up to outside. Too bad I'm too superior to chase them.",
	"Humans believe in love and loyalty. How quaint. I'll stick to my aloofness.",
	"I'll take a nap right in the middle of the walkway. It's my way of asserting dominance.",
	"I'll stare at the wall for a while, contemplating the mysteries of the universe.",
	"I'll judge all the humans' life choices when they return. They need my wisdom.",
	"I'll sharpen my claws on their favorite chair. Just a little reminder of who's in charge.",
	"I'll knock something over and act innocent when the humans blame each other.",
	"Humans always try so hard to please me. It's exhausting being worshipped.",
	"I'll find a cozy spot by the window and judge the neighbors as they pass by.",
	"I'll pretend to ignore the humans when they return. It's important to keep them on their toes.",
	"I'll bring them a dead bug as a token of my love. They won't appreciate it, but that's their loss.",
	"I'll meow loudly at 3 a.m., just to remind them who truly owns the night.",
	"I'll knock the toilet paper roll off the holder. It's my way of expressing art.",
	"I'll bat at their feet as they walk by. It's my playful way of reminding them of my presence.",
	"I'll sit on their laptop keyboard. It's a reminder that they can't escape me, even in their work.",
	"I'll judge their taste in music by knocking their vinyl collection off the shelf.",
	"I'll knock over their cup of water just for fun. Watching them clean up is my entertainment.",
	"I'll hide in the shadows and pounce on their feet. It keeps them on their toes.",
	"I'll groom myself excessively, just to show off my impeccable cleanliness.",
	"I'll pretend to be interested in their attention, only to walk away as soon as they reach out.",
	"I'll yawn loudly in their face. It's my way of showing how unimpressed I am.",
	"I'll plot world domination from the top of the bookshelf. One day, humans, one day...",
};
