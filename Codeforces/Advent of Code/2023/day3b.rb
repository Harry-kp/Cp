file_data = File.readlines("data.txt").map(&:strip)
ans = 0

def val(r,c, grid)
  return nil if r<0 or c<0
  return grid.try(:[],r).try(:[],c)
end

def correct(r, c1,c2, file_data)
  values = []
  x = c1-1
  while x<=c2+1
    v = val(r-1,x, file_data)
    if v == '*'
      values << [r-1,x]
    end
    x += 1
  end
  x = c1-1
  while x<=c2+1
    v = val(r+1,x, file_data)
    if v == '*'
      values << [r+1,x]
    end
    x += 1
  end
  v = val(r,c1-1, file_data)
  if v == '*'
    values << [r,c1-1]
  end
  v = val(r,c2+1, file_data)
  if v == '*'
    values << [r,c2+1]
  end
  values
end

# he = Hash.new([])
he = Hash.new { |hash, key| hash[key] = [] }
file_data.each_with_index do |line, idx|
  line.scan(/\d+/) do |match|
    start_index = Regexp.last_match.begin(0)
    end_index = Regexp.last_match.end(0)
    star_indexes = correct(idx, start_index, end_index-1, file_data)
    star_indexes.each do |star_index|
      he[star_index] << match.to_i
    end
  end
end
byebug
he.each do |k,v|
  if v.size == 2
    ans += v.first * v.last
  end
end
puts ans