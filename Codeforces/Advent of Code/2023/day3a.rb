file_data = File.readlines("data.txt").map(&:strip)
ans = 0

def val(r,c, grid)
  return nil if r<0 or c<0
  grid.try(:[],r).try(:[],c)
end

def correct(r, c1,c2, file_data)
  values = []
  x = c1-1
  while x<=c2+1
    values << val(r-1,x, file_data)
    x += 1
  end
  x = c1-1
  while x<=c2+1
    values << val(r+1,x, file_data)
    x += 1
  end

  values << val(r,c1-1, file_data)
  values << val(r,c2+1, file_data)
  values = values.compact
  values.reject!{|v| v == '.'}
  values.present?
end


file_data.each_with_index do |line, idx|
  line.scan(/\d+/) do |match|
    start_index = Regexp.last_match.begin(0)
    end_index = Regexp.last_match.end(0)
    if correct(idx, start_index, end_index-1, file_data)
      ans += match.to_i
      puts "match #{match} - #{start_index} - #{end_index}"
    else
      puts "NO match #{match}"
    end
  end
end
puts ans


