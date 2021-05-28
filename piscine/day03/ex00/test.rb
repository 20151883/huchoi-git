#!/usr/bin/ruby
require "minitest/autorun"
require "deepthought"

class Deepthought_test < Minitest::Test
  def setup
    @meme = Deepthought.new
  end

  def test_that_kitty_can_eat
    assert_equal @meme.respond("The Ultimate Question of Life, the Universe and Everything"), "42"
    assert_equal @meme.respond("this is test"), "Mmmm i'm bored"
    assert_equal @meme.class.to_s, "Deepthought"
    assert @meme.class, "this is test"
    assert_equal @meme.class, "this is test"
  end

  #def test_that_it_will_not_blend
   # refute_match /^no/i, @meme.will_it_blend?
  #end


  #def test_that_will_be_skipped
  #  skip "test this later"
  #end
end
