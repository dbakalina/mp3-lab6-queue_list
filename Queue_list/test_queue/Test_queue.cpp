#include"gtest.h"
#include "../Queue_list/Queue.h"

TEST(Queue, can_create_queue)
{
    ASSERT_NO_THROW(TQueue<int> q);
}

TEST(Queue, the_copied_queue_is_the_same_as_the_original_one)
{
    TQueue<int> q;
    q.Push(7);
    ASSERT_NO_THROW( TQueue<int> copy(q)) ;
}

TEST(Queue, can_copy_the_queue)
{
    TQueue<int> q;
    q.Push(7);
    ASSERT_NO_THROW(TQueue<int> copy(q));
}

TEST(Queue, can_assign_empty_queue)
{
    TQueue<int> q1;
    TQueue<int> q2;
    ASSERT_NO_THROW(q1 = q2);
}

TEST(Queue, can_compare_queue)
{
    TQueue<int> q1;
    TQueue<int> q2;
    q1.Push(7);
    q2.Push(4);
    ASSERT_NO_THROW(q2 == q1);
}

TEST(Queue, can_compare_the_queue_with_itself)
{
    TQueue<int> q;
    EXPECT_EQ(true, q == q);
}

TEST(Queue, can_compare_the_same_queue)
{
    TQueue<int> q1;
    TQueue<int> q2;
    q1.Push(7);
    q2.Push(7);
    EXPECT_EQ(true, q1 == q2);
}

TEST(Queue, comparing_different_queue_gives_the_false)
{
    TQueue<int> q1;
    TQueue<int> q2;
    q1.Push(5);
    EXPECT_EQ(true, q1 != q2);
}

TEST(Queue, can_check_the_queue_for_emptiness)
{
    TQueue<int> q;
    ASSERT_NO_THROW(q.Empty());
}

TEST(Queue, viewing_the_top_of_the_queue_does_not_change_the_state_of_the_stack)
{
    TQueue<int> q;
    q.Push(2);
    int x = q.SeeHead();
    EXPECT_EQ(x, q.SeeHead());
}

TEST(Queue, checking_for_the_emptiness_of_a_non_empty_queue_returns_false)
{
    TQueue<int> q;
    q.Push(7);
    EXPECT_EQ(false, q.Empty());
}

TEST(Queue, can_add_to_an_incomplete_queue)
{
    TQueue<int> q;
    ASSERT_NO_THROW(q.Push(3));
}

TEST(Queue, can_see_what_is_at_the_top_of_a_non_empty_queue)
{
    TQueue<int> q;
    q.Push(3);
    ASSERT_NO_THROW(q.SeeHead());
}

TEST(Queue, cant_look_at_the_top_of_an_empty_queue)
{
    TQueue <int> q;
    ASSERT_ANY_THROW(q.SeeHead());
}

TEST(Queue, can_take_an_element_from_a_non_empty_non_empty_queue)
{
    TQueue<int> q;
    q.Push(3);
    ASSERT_NO_THROW(q.GetHead());
}

TEST(Queue, cant_take_an_element_from_an_empty_queue)
{
    TQueue<int> q;
    ASSERT_ANY_THROW(q.GetHead());
}

TEST(Queue, can_correcttly_get_elem_from_the_queue)
{
    TQueue<int> q;
    q.Push(2);
    EXPECT_EQ(q.GetHead(), 2);
}