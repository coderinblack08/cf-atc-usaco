defmodule Solution do
  def part1() do
    File.read!("input.txt")
    |> String.split("\n", trim: true)
    |> Enum.reduce({0, 0}, fn
      "forward " <> number, {depth, position} ->
        {depth, String.to_integer(number) + position}

      "down " <> number, {depth, position} ->
        {depth + String.to_integer(number), position}

      "up " <> number, {depth, position} ->
        {depth - String.to_integer(number), position}
    end)
    |> then(fn {depth, position} -> depth * position end)
  end

  def part2() do
    File.read!("input.txt")
    |> String.split("\n", trim: true)
  end
end

defmodule Submarine do
  def navigate("forward " <> number, {depth, position, aim}) do
    number = String.to_integer(number)
    {depth + aim * number, position + number, aim}
  end
end

IO.puts(Solution.part1())
