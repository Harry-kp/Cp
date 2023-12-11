file_data = File.readlines("data.txt").map(&:strip)
ans = 0

file_data.each_with_index do |line, idx|
  card, left,right = line.split(Regexp.union([':','|']))
  byebug
  left = left.split.map(&:to_i)
  right = right.split.map(&:to_i)
  c = (left & right).size
  if c > 0
    c-=1
    ans += 2 ** c
  end
end
puts ans