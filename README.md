# Philosophers, the dining problem

Imagine a group of philosophers enter a restaurant to have dinner together. They chose a sushi place, very famous in town for being \~edgy~. The funky thing about this place is that each guest receives one hashi (only one) and they have to switch and share in order to enjoy the delicious expensive food being served. How should they organize themselves?

<p align="center">
  <img src="https://res.cloudinary.com/practicaldev/image/fetch/s---imrjIOF--/c_limit%2Cf_auto%2Cfl_progressive%2Cq_auto%2Cw_350/https://res.cloudinary.com/studio-mogwai/image/upload/v1581865192/Untitled_Artwork_5.png" />
</p>


This scenario, known as the [dining philosophers problem](https://en.wikipedia.org/wiki/Dining_philosophers_problem), is a classic brainteaser in computer science. It's used to show how programs can get stuck if they don't share resources carefully.

The goal is to design a system where all the philosophers can eat eventually, without anyone hogging all the hashis or getting stuck waiting forever. The program acts as a kind of restaurant maitre, making sure everyone gets a turn to eat and nobody dies out of hunger.
<br><br>

## The rules

A few parameters are given to the program: how many **philosophers** are there, how much time from the start of the last meal they take to **die**, how long they spend **eating** (holding two hashis) and for how long should they **nap** after each meal. Optionally, you can input how many meals should everyone eat.

How each philo should behave:
- Think unless the left hashi is available; when it is, pick it up.
- Think unless the right hashi is available; when it is, pick it up.
- When both hashis are being held, eat for the determined amount of time.
- After eating, put both hashis down.
- Sleep for the determined amount of time.
- Repeat the process indefinitely or until the maximum number of meals is reached.

<br>

In the mandatory part of this project, each philosopher is a `thread` and each hashi is a `mutex`. We must prevent deadlocks and starvation, as well as guarantee that no two philosophers can access any of the resources at the same time, a phenomenon known as **data race**.

For the bonus, each philo becomes a `process` and the hashis are all now collectively managed in the form of a `semaphore`, that exists in a shared memory space and can be taken by anyone at any time, as if they are all in the center of the table.
<br><br>

<p align="center">
  <img src="https://media.discordapp.net/attachments/819418940987670558/1240117661526917131/image.png?ex=66456512&is=66441392&hm=ec158cd83cbd8510d3303bb2588ac199922189dd94df58d33a5a06de13724c9e&" /><br>
  ./philo 2 310 200 100
</p>

## Play around with the program!

Clone the repository to your local machine using the command below.

```bash
git clone git@github.com:jlbernardo/philosophers.git
```

At the root of the repository, you can find one folder for the mandatory solution, using threads and mutexes, and another for the bonus solution, using processes and semaphores. Enter the folder of your choice and run `make` to compile the program.

<br>

Some interesting tests you can run (valid for the bonus as well):

`./philo 1 800 200 200` - the philosopher does not eat and die.

`./philo 5 800 200 200` - nobody dies.

`./philo 4 310 200 100` - one philosopher dies.

`./philo 5 800 200 200 7` - nobody dies and each philosopher eats 7 times or more.
<br><br>

### Note:

Do not test with more than 200 philosophers or with times lower than 60ms, as the program may not be able to handle it. By the rules of the project's subject, the deaths must be reported with no more than 10ms of delay.
