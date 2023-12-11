file_data = File.readlines("data.txt")
ans = 0
file_data.each do |line|
  game, lots = line.split(':')
  game_id = game.split(' ')[1].to_i
  lots = lots.split(Regexp.union([';',','])).map(&:strip)
  r = 0
  b = 0
  g = 0
  lots.each do |lot|
    q,color = lot.split(' ')
    r = [r,q.to_i].max if color == 'red'
    b = [b,q.to_i].max if color == 'blue'
    g = [g,q.to_i].max if color == 'green'
  end
  ans += (r*g*b)
end
puts ans
